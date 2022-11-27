#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int TAILLE_MAX_TAB = 1000000;

void recopie_tableau(int t1[],int t2[], int n){
    for(int i = 0; i<n ;i++){
        int tmp = t2[i];
        t2[i]=t1[i];
        t1[i]= tmp;
    }
}

void affiche_tab(int tab[]){
    printf("[");
    printf("%d", tab[0]);
    for(int i = 1; i<TAILLE_MAX_TAB;i++){
        printf(", %d", tab[i]);
    }
    printf("]\n");
}
void remplir_alea(int tab[]){
    for(int i = 0; i< TAILLE_MAX_TAB; i++){
        tab[i] = (rand()%100)+1; 
    }
}
int tri_bulle(int tab[], int n){
    int finish=1;
    for(int i =0; i<n-1;i++){
        if(tab[i]>tab[i+1]){
            finish = 0;
            int tmp = tab[i+1];
            tab[i+1] = tab[i];
            tab[i] = tmp;
        }
    }
    return finish;
}
void tri_tabV1(int tab[]){
    for(int i = 0; i <TAILLE_MAX_TAB ; i++){
        tri_bulle(tab, TAILLE_MAX_TAB);
    }
}
void tri_tabV2(int tab[]){
    while(!tri_bulle(tab, TAILLE_MAX_TAB)){
        
    }
}
void tri_tabV3(int tab[]){
    int i = 0;
    while(!tri_bulle(tab, TAILLE_MAX_TAB-i)){
        i++;
    }
}

int main(){
    srand(time(NULL));
    int t1[5] = {1,2,3,4,5};
    int t2[5] = {5,4,3,2,1};
    int alea[TAILLE_MAX_TAB];
    recopie_tableau(t1,t2,5);
    remplir_alea(alea);
    
    clock_t temps_initiale,
    temps_finale;
    double temps_exec;
    temps_initiale = clock();
    tri_tabV3(alea);
    temps_finale = clock();
    temps_exec = (temps_finale-temps_initiale) * 1e-6;
    printf("temps execution : %e\n", temps_exec);
}