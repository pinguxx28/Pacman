/*
	Author:	pinguxx28
	Date:	8th of May 2022
*/

#ifndef __CONSTS_H
#define __CONSTS_H

#include <stdint.h>
#include "raylib.h"

/* Macros */
#define exit_func(con) ({ if (con) return; })

/* Constants */
enum {
	TILE_SIZE		= 32,
	MAP_WIDTH		= 19,
	MAP_HEIGHT		= 21,
	MAP_SIZE		= MAP_WIDTH  * MAP_HEIGHT,
	DISP_WIDTH		= MAP_WIDTH  * TILE_SIZE,
	DISP_HEIGHT		= MAP_HEIGHT * TILE_SIZE,
	LIVES_AMOUNT	= 3,
	DOTS_AMOUNT		= 144,
	WALLS_AMOUNT	= 199,
	PILLS_AMOUNT	= 4,

	PACMAN_RADIUS	= TILE_SIZE / 3,
	PACMAN_MINFRAME = 5,
	PACMAN_MAXFRAME = 45,
	PACMAN_FRAMEINC = 15,
};

typedef enum {
	GAMESTATE_INTRO,
	GAMESTATE_GAME,
	GAMESTATE_END,
	NUM_GAMESTATE,
} Gamestate_t;

typedef enum {
	GHOSTSTATE_NONE,
	GHOSTSTATE_CHASE,		/* All ghosts chasing pacman			*/
	GHOSTSTATE_SCATTER,		/* Scatter all ghosts to corners		*/
	GHOSTSTATE_FRIGHTENED,	/* Pacman has eaten a energizer pill	*/
	GHOSTSTATE_EATEN,		/* Ghost was just eaten by pacman		*/
	GHOSTSTATE_HOUSE,		/* Ghosts inside the ghost house		*/
	GHOSTSTATE_LEAVEHOUSE,	/* Ghosts leaving the ghost house		*/
	GHOSTSTATE_ENTERHOUSE,	/* Ghosts entering the ghost house		*/
	NUM_GHOSTSTATES,
} Ghoststate_t;

typedef enum {
	GHOSTTYPE_BLINKY,
	GHOSTTYPE_PINKY,
	GHOSTTYPE_INKY,
	GHOSTTYPE_CLYDE,
	NUM_GHOSTS,
} Ghosttype_t;

typedef enum {
	PACMAN_MOVEMENT_SPEED	= 8,
	GHOST_CHASE_SPEED		= 8,
	GHOST_SCATTER_SPEED		= 4,
	GHOST_HOUSE_SPEED		= 2,
	GHOST_ENTERHOUSE_SPEED	= 16,
	GHOST_LEAVEHOUSE_SPEED	= 8,
} Speed_t;

#define PACMAN_COLOR YELLOW

typedef enum {
	PACMAN_START_X = TILE_SIZE,
	PACMAN_START_Y = TILE_SIZE,
} Positions_t;

typedef struct {
	int16_t x;
	int16_t y;
} Vector2_t;

typedef Vector2_t Position_t;
typedef Vector2_t Direction_t;

typedef struct {
	uint64_t tick;
} Tick_t;

#endif