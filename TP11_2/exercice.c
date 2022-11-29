#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 5

typedef struct feuille{
    int nbl;
    int nbc;
    float tab[TAILLE][TAILLE];
}feuille;

feuille exemple(){
    feuille f;
    f.nbc = TAILLE;
    f.nbl = TAILLE;
    for(int l = 0; l<f.nbl; l++){
        for(int c = 0; c<f.nbc; c++){
            f.tab[l][c] = ((float)(rand()%10000))/100;
        }
    }
    return f;
}
void afficher(feuille f){
    printf("Tableau :\n");
    for(int l = 0; l<f.nbl; l++){
        for(int c = 0; c<f.nbc; c++){
            printf("%8.2f", f.tab[l][c]);
        }
        printf("\n");
    }
}
void afficher_somme(feuille f){
    float somme = 0;
    printf("Somme :\n");
    for(int l = 0; l<f.nbl; l++){
        for(int c = 0; c<f.nbc; c++){
            somme += f.tab[c][l];
        }

        printf("%8.2f", somme);
        somme = 0;
    }
    printf("\n");
}
void echanger(feuille *f, int l1, int l2){
    float temp; 
    for(int i = 0; i < TAILLE; i++ ){
        temp = f->tab[l1][i];
        f->tab[l1][i] = f->tab[l2][i];
        f->tab[l2][i] = temp;
    }
}
//tri par selection
void trier(feuille *f, int col){
    int min = 0;
    for(int i = 0; i<TAILLE-1; i++){
        min = i;
        for(int j = i;j<TAILLE;  j++){
            if(f->tab[j][col]<f->tab[min][col]){
                min =j;
            }
        }
        echanger(f, min, i);
    }
}
int est_egal(feuille f1, feuille f2){
    for(int i = 0; i<TAILLE; i++){
        for(int j = 0;j<TAILLE;  j++){
            if(f1.tab[i][j]!=f2.tab[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
void transposer(feuille *f){
    float trans;
    for(int l = 0; l < TAILLE; l++){
        for(int c = l; c < TAILLE; c++){
            trans = f->tab[l][c];
            f->tab[l][c] = f->tab[c][l];
            f->tab[c][l] = trans;
        }
    }
}
void met_diag_nule(feuille *f){
    for(int i = 0; i < TAILLE; i++){
        f->tab[i][i] = 0; 
    }
}

void rend_tout_positif(feuille *f){
    for(int l = 0; l < TAILLE; l++){
        for(int c = l; c < TAILLE; c++){
            if(f->tab[l][c]<0){
                f->tab[l][c] *= -1;
            }
        }
    }
}
void rend_symetrique(feuille *f){
    for(int l = 0; l < TAILLE; l++){
        for(int c = l; c < TAILLE; c++){
            if(f->tab[l][c]>f->tab[c][l]){
                f->tab[l][c] = f->tab[c][l];
            }
            else{
                f->tab[c][l] = f->tab[l][c];
            }
        }
    }
}
int main(){
    srand(time(NULL));
    feuille f = exemple();
    afficher(f);
    met_diag_nule(&f);
    rend_tout_positif(&f);
    rend_symetrique(&f);
    afficher(f);
    //trier(&f,0);
    //afficher(f);
    //afficher_somme(f);
    return 0;
}