#include "canvas.h"
#include "canvas.h"
#include <stdio.h>
#include <stdlib.h>

struct canvas_t {
    char *table;
    unsigned size;    
};


canvas  create_canvas(unsigned int size){
    canvas gr;

    if ( ((gr=malloc(sizeof(struct canvas_t)))==NULL) ||
	 ((gr->table=malloc(size*size))==NULL)){
	fprintf(stderr, "problem : memory allocation\n");
	exit(1);
    }
    gr->size=size;
    
    for(int i=0; i<gr->size;i++)
	for(int j=0;j<gr->size;j++)
	    gr->table[i*gr->size+j]=' ';

    return gr;
}




int get_size(canvas c){
    return c->size;
}
    
void set(canvas gr, int line,  int column, char c){
    if (line < 0 || column <0 || line>(gr->size-1) || column>(gr->size-1)){
	fprintf(stderr,"(%d, %d) out of the canvas\n",line, column);
    }
    gr->table[line*gr->size+column]=c;
}

char get(canvas gr, int line,  int column){
    if (line < 0 || column <0 || line>(gr->size-1) || column>(gr->size-1)){
	fprintf(stderr,"(%d, %d) out of the canvas\n",line, column);
    }
    return gr->table[line*gr->size+column];
}

void ligne_cadre(int n,char bord){
    printf("%c", bord);
    for(int i=0; i<n;i++)
	printf("%c", '0'+i%10);
    printf("%c\n", bord);
}


void plot(canvas gr){

    char bord='.';
    
    ligne_cadre(gr->size,bord);

    for(int i=0; i<gr->size;i++){
	char c='0'+i%10;
	    printf("%c", c);
	for(int j=0;j<gr->size;j++)
	    printf("%c",gr->table[j*gr->size+i]);
	printf("%c\n", c);
    }
    ligne_cadre(gr->size,bord);
}

