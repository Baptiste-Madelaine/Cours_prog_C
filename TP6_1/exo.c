#include <stdio.h>

void saisir_valeur(int n, int tab[]){
    for(int i = 0; i<n;i++){
        printf("Saisir la valeur: \n");
        int val;
        scanf("%d", &val);
        tab[i] = val;
    }
}
int plus_grande_valeur(int n, int tab[]){
    int max = 0;
    for(int i = 0; i<n;i++){
        if(tab[i]>max){
            max = tab[i];
        }
    }
    return max;
}
int is_in(int n, int tab[], int x){
    for(int i = 0; i<n ; i++){
        if(tab[i]==x){
            return 1;
        }
    }
    return 0;
}
int upper_then_10(int n ,int tab[]){
    int nbr = 0;
    for(int i = 0; i<n;i++){
        if(tab[i]>=10){
            nbr++;
        }
    }
    return nbr;
}
int croissant(int n, int tab[]){
    for(int i = 1; i<n; i++){
        if(tab[i-1]>tab[i]){
            return 0;
        }
    }
    return 1;
}
int somme_tab(int n, int tab[]){
    int somme=0;
    for(int i = 0; i<n; i++){
        somme += tab[i];
    }
    return somme;
}
int suite(int n){
    int tab[n];
    if(n<=2)return 1;
    tab[0]=1;
    tab[1]=1;
    for(int i = 2; i<n; i++){
        tab[i]= tab[i-1]+tab[i-2];
    }return tab[n-1];
}
void affiche_tab(int n, int tab[]){
    for(int i = 0; i<n; i++){
        if(tab[i]==0){printf(" ");}
        else{printf("%d", tab[i]);}
    }
    printf("\n");
}
void echange(int n, int tab1[],int tab2[]){
    int temp[n];
    for(int i = 0; i<n; i++){
        temp[i] = tab1[i];
        tab1[i] = tab2[i];
        tab2[i] = temp[i];
    }
}
void triangle_pascale(int n){
    int tab1[n+1];
    int tab2[n+1];
    for(int i = 0; i<n; i++){
        tab1[i] = 0;
    }
    affiche_tab(n+1,tab1);
    tab1[n]=1;
    for(int i = 0; i<n;i++){
        tab2[i] = tab1[i]+tab1[i+1];
    }
    affiche_tab(n+1,tab2);
    tab2[n+1] = 0;
    echange(n+1, tab1,tab2);
}

int main(){
    int n = 5;
    int tab[5];
    triangle_pascale(3);
}