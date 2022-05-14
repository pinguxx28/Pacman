#ifndef __GHOST_H
#define __GHOST_H
#include "raylib.h"
#include "consts.h"

/*  Variables  */
typedef struct {
	Position_t		pos;
	Direction_t		dir;
	Position_t		target;
	Ghosttype_t		type;
} Ghost_t;

extern Ghost_t ghosts[GHOST_AMOUNT];

/*  Sub  functions  */


/*  Main functions  */
void initGhosts  (void);
void drawGhosts  (void);
void updateGhosts(void);

#endif