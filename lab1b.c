
/*
 * This code allows users to play out conways game of life. It provides a
 * default glidder pattern, however users can input their own pattern files.
 * 
 *      Author:Gagandeep Sandhu
 */

/* include helper functions for game */
#include "lifegame.h"
#include <stdio.h>

/* number of generations to evolve the world */
#define NUM_GENERATIONS 50

/* this function should set the state of all
   the cells in the next generation and call
   finalize_evolution() to update the current
   state of the world to the next generation */
void next_generation(void);

/* this function should return the state of the cell
   at (x,y) in the next generation, according to the
   rules of Conway's Game of Life */
int get_next_state(int x, int y);

/* this function should calculate the number of alive
   neighbors of the cell at (x,y) */
int num_neighbors(int x, int y);

int main(int argc, char ** argv)
{
	/* Initialize the world, from input
	   if input is empty, then use the default glider
        */
  int n, Generations = 50;
  char filen[20];
  char filew[20];

  /*collect user input*/
  printf("What is the name of the Pattern file:\n");
  scanf("%s",filen);
  printf("What is the name of the output file:\n");
  scanf("%s",filew);
  printf("What is the number of generations?:\n");
  scanf("%d",&Generations);

  initialize_world_from_file(filen);

  output_world();
  for (n = 0; n < Generations; n++)
    next_generation();

  /* TODO: output final world state to console and save
     world to file "world.txt" in current directory */
  output_world();
  save_world_to_file(filew);
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
