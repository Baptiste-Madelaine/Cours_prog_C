#include <stdio.h>
#include "board.h"

/**
 * @file main_example.c
 * @brief a simple illustration of how to include and use board.h and board.o.
 * @author Dorbec
 */

/**
 * @brief the main function
 * This function builds a game, put a piece in the game, then destroy it, 
 * in order to make an example of how to use the board.o file.
 * @return 0, as a standard return value for a main function.
 **/
int main(){
	board game = new_game();
	printf("Un plateau est créé.\n");
	int res = place_piece(game, SMALL, 0, 2);
	if(res == OK){
		printf("La piece a été placée avec succès.\n");
	}
	else {
		printf("Un problème a eu lieu lors du placement, numéro %d\n", res);
	}
	destroy_game(game);
	printf("suppression du plateau et sortie\n");	
	return 0;
}
