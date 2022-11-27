#ifndef __CANVAS__
#define __CANVAS__

typedef struct canvas_t*  canvas;

// creation d'une surface de dessin de dimension dim
canvas create_canvas(unsigned int dim);
// la fonction set positionne un caractère à la positioon col, lig
void set(canvas c, int col, int lig, char caractere);

// la fonction get retourne le caractère à la positioon col, lig
char get(canvas c, int col,  int lig);

// la fonction get_size retourne la dimensioon de la surface de dessin
int get_size(canvas);

// plot affiche la surface de dessin sur le terminal.
void plot(canvas c);

#endif
