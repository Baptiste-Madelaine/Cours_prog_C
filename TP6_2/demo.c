#include "canvas.h"

 void demo(){
    canvas c=create_canvas(7);
    set(c, 0, 0,'*');
    set(c, 1, 1,'*');
    set(c, 2, 2,'*');
    set(c, 3, 3,'*');
    set(c, 6, 0,'*');
    set(c, 5, 1,'*');
    set(c, 4, 2,'*');
    plot(c);
}

void damier(){
    canvas c = create_canvas(7);
    for(int i = 0; i<7; i++){
        for (int t = 0; t < 7; t++)
        {
            if((t+i)%2 != 0){
                set(c,t,i,'X');
            }
        } 
    }
    plot(c);
}
void diagonale(){
    canvas c = create_canvas(7);
    for(int i = 0; i<7; i++){
        for(int t = 0; t<7; t++){
            set(c,t,t,'X');
        }
    }
    plot(c);
}
void deuxieme_diag(){
    canvas c = create_canvas(7);
    for (int i = 0; i <= 7; i++)
    {
        set(c,i,6-i,'X');
    }
    plot(c);
    
}
void un_carre(canvas c,int cote, int column, int line){
    for(int i = 0;i<7;i++){
        for (int t= 0; t < 7; t++)
        {
            /*if(i<=(line+cote-1)&&(i>line-1) && t<=(column+cote-1) && t>column-1){
                set(c,t,i,'X');
            }*/
            /*if((t==(column+cote-1)|t==column-1)(i<=(line+cote-1)&&(i>line-1))){
                set(c,t,i,'X');
            }*/
            if((i<(line+cote)&& i>line-1)&& (t<column+cote&&t>=column)){
                
                if(t==column| t==column+cote-1){
                   set(c,t,i,'X'); 
                }
                if(i==line | i == line+cote-1){
                    set(c,t,i,'X');
                }
            }
        }
    }
}
void test_test(){
    canvas c = create_canvas(7);
    un_carre(c,4,2,2);
    plot(c);
}


int main()
{
    deuxieme_diag();
    test_test();
}
