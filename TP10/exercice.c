#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAILLE_MAX 30

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
    for(int i = 0; i<n; i++){
        printf("%d\n", p[i].date_naiss.jour);
    }
}
void generer_n(int n){
    personne tab[TAILLE_MAX];
    int i = 0;
    while (i<TAILLE_MAX)
    {
        tab[i] = personne_aléatoire();
        i++;
    }
    afficher_tab(tab, n);
    
}



int main(){
    srand(time(NULL));
    personne p ={
        "Paul",
        "Dorbec",
        {
            12,12,2000
        }
    };
    affiche_personne(p);
    //lire_personne();
    generer_n(10);
    return 0;
}