#include <stdio.h>
#include "ppm.h"
char rot13(char c){
    if(c>'a' || c<'z'){
        if(c+13 > 'z'){
            c = (c-26)+13;
        }else{
            c += 13;
        }
    }else{
        return 0;
    }
    return c;
}
void coder(char chaine[]){
    int i = 0;
    while(chaine[i]!='\0'){
        printf("%c", rot13(chaine[i]));
        i++;
    }
    printf("\n");
}
void coder_dans_fichier(char fsource[], char fdest[]){
    FILE *fs = fopen(fsource,"r");
    char c = ' ';
    FILE *fd = fopen(fdest, "w");
    while(fscanf(fs,"%c", &c)!=EOF){
        fprintf(fd,"%c",c);
    }
    fclose(fs);
    fclose(fd);

}
int est_sans_repetition(int tab[], int taille){
    int temp = tab[0];
    for(int i = 1; i<taille; i++){
        if(tab[i]==temp){
            return 0;
        }
        temp = tab[i];
    }
    return 1;
}

int longueur_repetition(int tab[], int taille){
    int longueur = 1;
    int long_max=0;
    int temp = tab[0];
    for(int i = 1; i<taille; i++){
        
        if(tab[i]==temp){
            longueur++;
            if(long_max<=longueur){
                long_max = longueur;
            }
        }else{
            longueur=1;
        }
        //printf("car : %d\nlong : %d\n", tab[i], longueur);
        temp=tab[i];
    }
    return long_max;
}
void sans_repetition(int tab[], int resultat[], int taille,int* ptr_taille_resultat){
    int temp = tab[0];
    resultat[0] = temp;
    int t = 0;
    for(int i = 1; i < taille; i++){
        if(tab[i]!=temp){
            resultat[t]=tab[i];
            t++;
            *ptr_taille_resultat += 1;
        }
        temp = tab[i];
    }
}
void drapeau_Français(int unite){
    struct imagePPM deg = allouer_image_vide_PPM(unite*2,
         unite*3, 255);
    struct pixelRVB bleu = {5, 20, 64};
    struct pixelRVB blanc = {255, 255, 255};
    struct pixelRVB rouge = {236, 55, 32};
    for(int l = 0; l < unite*2; l++){
        for(int c = 0; c < unite*3; c++){
            putPixel(&deg, rouge, l, c);
            if(c<unite){
                putPixel(&deg,bleu, l, c);
            }else if(c>=unite && c<=unite*2){
                
                putPixel(&deg,blanc, l, c);
            }
        }
    }
    ecrire_image_PPM(deg,"drapeau_FR.ppm");
}
void drapeau_Suedois(int unite){
    struct imagePPM deg = allouer_image_vide_PPM(unite*10,
         unite*16, 255);
    struct pixelRVB bleu = {0, 90, 173};
    struct pixelRVB jaune = {255, 194, 0};
    for(int l = 0; l < unite*10; l++){
        for(int c = 0; c < unite*16; c++){
            putPixel(&deg, bleu, l, c);
            if((l<=unite*6 && l>=unite*4)||(c<=unite*7 && c >=unite*5)){
                putPixel(&deg, jaune, l,c);
            }   
        }
    }
    ecrire_image_PPM(deg,"drapeau_Suedois.ppm");
}
int main(){
    char c[] = "ouijeunehomme";
    int tab[]= {1,1,2,4,4,4,1,3,3,5,6,2,1,1};
    coder(c);
    coder_dans_fichier("tests.txt", "testd.txt");
    printf("%d\n", longueur_repetition(tab,14));
    drapeau_Français(50);
    drapeau_Suedois(50);
    return 0;
}