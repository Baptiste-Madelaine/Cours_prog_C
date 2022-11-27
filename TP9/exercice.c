#include <stdio.h>
#include "pile.h"

int longueur(char tab[]){
    int i = 0;
    while (tab[i] != '\0')
    {
        i++;
    }
    return i;
    
}
void inverstr(char tab[]){
    char tampon[longueur(tab)];
    for(int i = 0; i<longueur(tab); i++){
        tampon[i] = tab[longueur(tab)-1-i];
    }
    for(int i = 0; i<longueur(tab); i++){
        tab[i] = tampon[i];
    }
}

int verifie_expression(char tab[]){
    int compte = 0; 
    for(int i = 0; i < longueur(tab); i++){
        if(tab[i] == '('){
            compte++;
        }else if (tab[i] == ')' && compte>0){
            compte--;
        }
    }
    return compte == 0;
}
int verifie_expression_2(char tab[]){
    pile_s p;
    init(&p);
    for(int i = 0; i < longueur(tab); i++){
        if(tab[i] == '(' || tab[i] == '['){
            empile(&p,tab[i]);
        }
        else if(tab[i] == ')' && p.pile[p.niveau - 1]=='('){
            
            depile(&p);
        }
        else if(tab[i] == ']' && p.pile[p.niveau - 1]=='['){
            depile(&p); 
        }else if(((tab[i] == ')' || tab[i] == ']')&& est_vide(p)) || (tab[i] ==']' && p.pile[p.niveau - 1]!='[')){
            return 0;
        }
    }
    return est_vide(p);
}
int est_un_mot_palindromique(char tab[]){
    char inverse[longueur(tab)];
    for(int i = 0; i<longueur(tab); i++){
        inverse[i] = tab[i];
    }
    inverstr(inverse);
    for(int i = 0; i<longueur(tab); i++){
        if(inverse[i] != tab[i]){
            return 0;
        }
    }
    return 1;
    

}

int main(){
    char test[] = "((oui))";
    inverstr(test);
    //printf("%c",test[2]);
    printf("%d\n", est_un_mot_palindromique("kayak"));
    
}
