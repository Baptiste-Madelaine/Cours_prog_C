#include <stdio.h>

int sont_valeurs_positive(int n, int tab[]){
    for(int i = 0; i<n; i++){
        if(tab[i]<0){
            return 0;
        }
    }
    return 1;
}
int nombre_avant(int n, int tab[]){
    int nbr = 0;
    for(int i = 0; i<n ; i++){
        if(tab[i]== -1)return nbr;
        nbr++;
    }
    return -1;
}
int demande(){
    int x;
    int y=0;
    do{
        if(y!=0){printf("Seulement 1, 2 ou 3 !\n");}
        printf("\nCombien ? ");
        scanf("%d",&x);
        y++;
    }while(x!=1 && x!=2 && x!=3);
    return x;
    
}
void affiche(int x, int y){
    printf("L'ordinateur a choisit %d !\n",y);
    printf("Il reste %d allumette(s) !\n",x);
}
int choix_smart(int n){
    switch (n%4)
    {
    case 0:
        return 3;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    
    default:
        return 3;
    }
}

void partie(){
    int tour_rest = 20;
    while(tour_rest>0){
        int choix_pc = choix_smart(tour_rest);
        tour_rest -= choix_pc;
        if(tour_rest<=0){printf("L'ordinateur à gagné gros naze !\n");break;}
        affiche(tour_rest, choix_pc);
        int choix = demande();
        tour_rest -= choix;
        if(tour_rest<=0){printf("Bien joué 🥵!\n");break;}
    }
}


int main(){
    partie();
}