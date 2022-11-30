#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define DIML 5
#define DIMC 5


typedef struct tab_cel{
    int nbl;
    int nbc;
    char tab_cel[DIML][DIMC];
}tab_cel;

tab_cel remplir(){
    tab_cel tc;
    tc.nbl = DIML;
    tc.nbc = DIMC;
    int alea;
    for(int l = 0; l < DIML; l++){
        for(int c = 0; c< DIMC; c++){
            alea = rand()%100;
            if(alea%2==0){
                tc.tab_cel[l][c] = 'o';
            }
            else{
                tc.tab_cel[l][c] = '.';
            }
        }
    }
    return tc;

}
int nb_vivantes(tab_cel tab, int l, int c){
    int viv = 0;
    /* Version sans "Chambre à air"
    if(l>0){
        if(tab.tab_cel[l-1][c]=='o'){
            viv++;
        }
    }
    if(l<tab.nbl){
        if(tab.tab_cel[l+1][c]=='o'){
            viv++;
        }
    }
    if(c>0){
        if(tab.tab_cel[l][c-1]=='o'){
            viv++;
        }
    }
    if(c<tab.nbc){
        if(tab.tab_cel[l][c+1]=='o'){
            viv++;
        }
    }
    if(l>0 && c>0){
        if(tab.tab_cel[l-1][c-1]=='o'){
            viv++;
        }
    }
    if(l>0 && c<tab.nbc){
        if(tab.tab_cel[l-1][c+1]=='o'){
            viv++;
        }
    }
    if(l<tab.nbl && c<tab.nbc){
        if(tab.tab_cel[l+1][c+1]=='o'){
            viv++;
        }
    }
    if(l<tab.nbl && c>0){
        if(tab.tab_cel[l+1][c-1]=='o'){
            viv++;
        }
    }*/
    int l_bis = l;
    int c_bis = c;
    if(l==0){
        l_bis = tab.nbl-1;
    }else if(l==tab.nbl-1){
        l_bis = 1;
    }
    if(c==0){
        c_bis= tab.nbc-1;
    }else if(c==tab.nbl-1){
        c_bis = 1;
    }
    for(int i = l_bis-1; i < l_bis+1; i++){
        for(int u = c_bis-1; u<c_bis+1; u++){
            if(tab.tab_cel[i][u] == 'o'){
                viv++;
            }
        }
    }
    return viv;
}

void afficher(tab_cel tab){
    for(int l = 0; l < tab.nbl; l++){
        printf("|");
        for(int c = 0; c < tab.nbc; c++){
            
            printf("%2c |", tab.tab_cel[l][c]);
        }
        printf("\n");
    }
}
void copie(tab_cel t1, tab_cel *t2){
    for(int l = 0; l <t1.nbl; l++){
        for(int c = 0; c <t1.nbc; c++){
            t2->tab_cel[l][c]=t1.tab_cel[l][c];
        }
    }
}
void suivant(tab_cel *tab){
    tab_cel t2 = remplir();
    copie(*tab, &t2);
    for(int l = 0; l <tab->nbl; l++){
        for(int c = 0; c <tab->nbc; c++){
            if(nb_vivantes(*tab, l, c)<2){
                t2.tab_cel[l][c] = '.';
            }
            if(nb_vivantes(*tab, l, c)==3){
                t2.tab_cel[l][c] = 'o';
            }
            if(nb_vivantes(*tab, l, c)>3){
                t2.tab_cel[l][c] = '.';
            }
        }
    }
    copie(t2, tab);
}
void afficher_jeu(int n){
    tab_cel p = remplir();
    afficher(p);
    for(int i = 0; i<n; i++){
        usleep(500000);
        printf("\033[2J");
        printf("Jour %d:", i);
        suivant(&p);
        printf("\n");
        afficher(p);
    }
}

int main(){
    srand(time(NULL));
    tab_cel p = remplir();
    afficher(p);
    int viv = nb_vivantes(p,0,0);
    printf("%d", viv);
    //afficher_jeu(10);
    return 0;
}