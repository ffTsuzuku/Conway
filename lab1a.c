/*
 * lab1a.c
 *
 *  Created on:
 *      Author:
 */

/* include helper functions for game */
#include "lifegame.h"
#include<stdio.h>
/* add whatever other includes here */

/* number of generations to evolve the world */
#define NUM_GENERATIONS 49

/* functions to implement */

/* this function should set the state of all
   the cells in the next generation and call
   finalize_evolution() to update the current
   state of the world to the next generation */
void next_generation(void);

/* this function should return the state of the cell
   at (x,y) in the next generation, according to the
   rules of Conway's Game of Life (see handout) */
int get_next_state(int x, int y);

/* this function should calculate the number of alive
   neighbors of the cell at (x,y) */
int num_neighbors(int x, int y);

int main(void)
{
	int n;

	/* TODO: initialize the world */
	initialize_world();

	
	for (n = 0; n < NUM_GENERATIONS; n++)
		next_generation();
	
	/* TODO: output final world state */

	output_world();
	return 0;
}

void next_generation(void) {
	/* TODO: for every cell, set the state in the next
	   generation according to the Game of Life rules
	   Hint: use get_next_state(x,y) */

  int worldW, worldH,w,h, state;
  worldW = get_world_width();
  worldH = get_world_height();

  for(w = 0; w < worldW; w++){
    for(h = 0; h < worldH; h++){
      set_cell_state(w,h,get_next_state(w,h)); 
    }
  }

  finalize_evolution(); /* called at end to finalize */
}

int get_next_state(int x, int y) {
	/* TODO: for the specified cell, compute the state in
	   the next generation using the rules

	   Use num_neighbors(x,y) to compute the number of live
	   neighbors */
  
  int neighbors, state, nstate;

  state = get_cell_state(x,y);
  neighbors = num_neighbors(x,y);

  if(neighbors < 2 || neighbors > 3)
    nstate = DEAD;
  else if((neighbors == 2 || neighbors == 3) && state == ALIVE)
    nstate = ALIVE;
  else if(neighbors == 3 && state == DEAD)
    nstate = ALIVE;
  else
    nstate = DEAD;

  return nstate;
}

int num_neighbors(int x, int y) {
	/* TODO: for the specified cell, return the number of
	   neighbors that are ALIVE

	   Use get_cell_state(x,y) */

  int total;
  total = get_cell_state(x-1,y-1) + get_cell_state(x,y-1)
    + get_cell_state(x+1,y-1) + get_cell_state(x-1,y) + get_cell_state(x+1,y) + 
    get_cell_state(x-1,y+1) + get_cell_state(x,y+1) + get_cell_state(x+1,y+1); 

  return total;
}
