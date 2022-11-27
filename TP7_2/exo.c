#include <stdio.h>

int longueur(char tab[]){
    int i = 0;
    while(tab[i]!='\0'){
        i++;
    }
    return i;
}

void affiche(char tab[]){
    for(int i = 0; i< longueur(tab); i++){
        printf("%c", tab[i]);
    }
}

int test_longueur(char tab[], int taille_test){
    int taille = longueur(tab);
    if(taille == taille_test){
        return 1;
    }
    return 0;
}
int lire_chaine_protegee(char tab[], int n){
    int i = 0;
    char chaine[n];
    scanf("%s", chaine);
    while (i<n && chaine[i] != '\0' && chaine[i]!=EOF)
    {
        tab[i] = chaine[i];
        printf("%c", chaine[i]);
        i++;
    }
    return i;
    
    
}
void en_majuscule(char tab[]){
    for(int i = 0;i<longueur(tab);i++){
        tab[i] = tab[i]-'a'+'A';
        printf("%c",tab[i]);
    }   
}
void en_minuscule(char tab[]){
    for(int i = 0; i< longueur(tab); i++){
        tab[i] = tab[i]+32;
        printf("%c",tab[i]);
    }
}
void freq(char tab[], int res[]){
    for(int i = 0; i < longueur(tab); i++){
        int x = tab[i]-65;
        res[x] +=1;
    }
}
void nbr_lettre(int res[]){
    for(int i = 0; i<longueur(res);i++){
        printf("%c: %d", i+65, res[i]);
    }
}


int main(){
    int alpha[58];
    char text[20] = "bonjour";
    printf("%d\n", longueur(text));
    lire_chaine_protegee(text,20);
    freq(text,alpha);
    nbr_lettre(text);


}