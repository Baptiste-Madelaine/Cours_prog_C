#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAILLE_MAX 20

typedef struct date {
    int jour;
    int mois;
    int annee;
}date;

typedef struct personne
{
    char prenom[TAILLE_MAX];
    char nom[TAILLE_MAX];
    date date_naiss;
}personne;
int taille(char tab[]){
    int i = 0;
    while(tab[i]!='\0'){
        i++;
    }
    return i;
}
void generate_name(char tab[]){
	int i, nb_cons = 15, nb_vow = 5;
	char vowels[5] = { 'a', 'e', 'i', 'o', 'u'};
	char consons[15 + 1] = "bcdfgjklmnprstv";
	int length = 2*(rand()%2)+4;
	for(i = 0; i < length; i ++){
		if(i%2){
			tab[i] = vowels[rand()%nb_vow];
		}
		else{
			tab[i] = consons[rand()%nb_cons];
		}	
	}
	tab[length]='\0';
}

void affiche_personne(personne pers){
    int i = 0;
    while (pers.nom[i] != '\0')
    {
        printf("%c", pers.nom[i]);
        i++;
    }
    i = 0;
    printf(" ");
    while (pers.prenom[i] != '\0')
    {
        printf("%c", pers.prenom[i]);
        i++;
    }
    printf(" ");
    printf("(%d/%d/%d)\n",pers.date_naiss.jour,pers.date_naiss.mois,pers.date_naiss.annee);   
}
/*
void lire_personne(){
    personne p;
    printf("Entrez le Prénom: ");
    scanf("%s", &p.prenom);
    printf("Entrez le Nom: ");
    scanf("%s", &p.nom);
    printf("Enrez le jour de naissance: ");
    scanf("%d", &p.date_naiss.jour);
    printf("Enrez le mois de naissance: ");
    scanf("%d", &p.date_naiss.mois);
    printf("Enrez l'année de naissance: ");
    scanf("%d", &p.date_naiss.annee);
    affiche_personne(p);

}*/
void serialiase_personne(struct personne p, FILE *f){
    fprintf(f,"%s,%s,%d,%d,%d\n", p.prenom,p.nom,p.date_naiss.jour,p.date_naiss.mois,p.date_naiss.annee);
}
personne personne_aléatoire(){
    personne p;
    generate_name(p.nom);
    generate_name(p.prenom);
    p.date_naiss.jour = rand()%30+1;
    p.date_naiss.mois = rand()%12+1;
    p.date_naiss.annee = rand()%100+1900;
    return p;
}
void afficher_tab(personne p[], int n){
    for(int i = 0; i<16; i++){
        printf("%s\n", p[i].prenom);
        printf("%s\n", p[i].nom);
        printf("%d\n", p[i].date_naiss.jour);
        printf("%d\n", p[i].date_naiss.mois);
        printf("%d\n", p[i].date_naiss.annee);
    }
}
void generer_n(int n, FILE *f){
    personne tab[TAILLE_MAX];
    int i = 0;
    while (i<TAILLE_MAX)
    {
        tab[i] = personne_aléatoire();
        serialiase_personne(tab[i],f);
        i++;
    }
    //afficher_tab(tab, n);
    
    
}
void vider_tab(char tab[]) {
  for (int i = 0; i < taille(tab); i++) {
    tab[i] = ' ';
  }
  tab[0]='\0';
}
void ecrire_dans_chaine(char nom[], char nom2[]){
    for(int i = 0; i < taille(nom2); i++){
        nom[i] = nom2[i];
    }
    nom[taille(nom2)-1]='\n';
    printf("%s\n", nom);
}
void lire_fich(FILE *f){
    char temp[8];
    personne tab_per[10];
    int flag=0;
    char c;
    int i = 0;
    int x = 0;
    while(fscanf(f,"%c", &c)!=EOF){
        if(c != ',' && c != '\n'){
            temp[i]=c;
            //printf("temp: %c\n",temp[i]);
            i++;
        }else if(c == ','){
            //printf(",\n");
            switch(flag){
                case 0:
                    printf("prénom : %s\n", temp);
                    ecrire_dans_chaine(tab_per[x].prenom, temp);
                    vider_tab(temp);
                    flag++;
                    break;
                case 1:
                    ecrire_dans_chaine(tab_per[x].prenom, temp);
                    vider_tab(temp);
                    flag++;
                    break;
                case 2:
                    tab_per[x].date_naiss.jour = atoi(temp);
                    vider_tab(temp);
                    flag++;
                    break;
                case 3:
                    tab_per[x].date_naiss.mois = atoi(temp);
                    vider_tab(temp);
                    flag++;
                    break;
                case 4:
                    tab_per[x].date_naiss.annee = atoi(temp);
                    vider_tab(temp);
                    flag=0;
                    break;
                i = 0;
            }
        }
        else if(c == '\n'){
            flag = 0;
            vider_tab(temp);
            x++;
            i = 0;
        }
        
    }
    printf("fin\n");
    afficher_tab(tab_per, TAILLE_MAX);
}


int main(){
    srand(time(NULL));
    FILE *f = fopen("test.txt", "a");
    //lire_personne();
    //generer_n(10,f);
    //printf("%d", taille("oui"));
    
    fclose(f);
    fopen("test.txt","r");
    lire_fich(f);
    fclose(f);
    return 0;
}