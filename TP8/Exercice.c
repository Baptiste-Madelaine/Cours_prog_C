#include <stdio.h>

enum mois {JANVIER,FEVRIER,MARS,AVRIL,MAI,JUIN,JUILLET,AOUT,SEPTEMBRE,OCTOBRE,NOVEMBRE,DECEMBRE};
typedef struct horaire
{
    int heure;
    int minute;
    int seconde;
} horaire;


void affiche_mois(enum mois MM){
    
    char mois[12][11] = {"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Décembre"};
    printf("%s\n", mois[MM]);
    
}
void affiche_horaire(horaire horaire){
    printf("H: %d  M: %d  S: %d\n",horaire.heure, horaire.minute, horaire.seconde);
}
void seconde_vers_horaire(int sjournee, horaire *horaire){
    horaire->heure = sjournee/3600;
    horaire->minute = (sjournee/60)%60;
    sjournee = sjournee%60;
    horaire->seconde = sjournee;
}
horaire saisir_horaire(){
    int h;
    int m;
    int s;
    printf("Rentrez le nombre d'heure :\n");
    scanf("%d", &h);
    printf("Rentrez le nombre de minutes :\n");
    scanf("%d", &m);
    printf("Rentrez le nombre de secondes :\n");
    scanf("%d", &s);
    horaire hor;
    hor.heure = h;
    hor.minute = m;
    hor.seconde = s;
    return hor;
}

struct horaire une_seconde_plus_tard(struct horaire ho){
    int sjournee = ho.heure*3600 + ho.minute * 60 + ho.seconde;
    struct horaire temp;
    seconde_vers_horaire(sjournee+1, &temp);
    return temp;
}

struct horaire duree(horaire h1, horaire h2){
    int h1_secondes = h1.heure*3600 +h1.minute*60 + h1.seconde;
    int h2_secondes = h2.heure*3600 + h1.minute*60 + h2.seconde;
    horaire h3;
    seconde_vers_horaire(h2_secondes-h1_secondes, &h3);
    return h3;
}
void table_mult(int x){
    for(int i = 1; i <= x; i++){
        for(int t = 1; t <= 10; t++){
            printf("%d * %d = %d\n", i, t, i*t);
        }
    }
}


int main(){
    affiche_mois(FEVRIER);
    horaire test = {12,5,55};
    seconde_vers_horaire(47531,&test);
    affiche_horaire(test);
    //horaire test2 = saisir_horaire();
    //affiche_horaire(test2);
    affiche_horaire(une_seconde_plus_tard(test));
    table_mult(50);

}