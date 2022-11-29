#include <stdio.h>
#include "board.h"

//#define DIMENSIONS 3
//#define NB_SIZE 3
//#define NB_INITIAL_PIECES 2
//#define NB_PLAYERS 2







int main(){
    board game = new_game();
    while (get_winner(game) == NO_PLAYER)
    {
        
    }
    
    return 0;
}