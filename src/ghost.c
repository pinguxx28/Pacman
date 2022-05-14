#include "ghost.h"



/*  Variables  */
Ghost_t ghosts[GHOST_AMOUNT];



/*  Sub  functions  */



/*  Main functions  */
void initGhosts  (void) {
	ghosts[0].pos		= (Position_t) { HOUSE_X, HOUSE_Y };
	ghosts[0].dir		= (Direction_t) { 1, 0 };
	ghosts[0].target	= (Position_t) { HOUSE_X, HOUSE_Y };
	ghosts[0].type		= GHOSTTYPE_BLINKY;

	ghosts[1].pos		= (Position_t) { HOUSE_X, HOUSE_Y };
	ghosts[1].dir		= (Direction_t) { 1, 0 };
	ghosts[1].target	= (Position_t) { HOUSE_X, HOUSE_Y };
	ghosts[1].type		= GHOSTTYPE_INKY;

	ghosts[2].pos		= (Position_t) { HOUSE_X, HOUSE_Y };
	ghosts[2].dir		= (Direction_t) { 1, 0 };
	ghosts[2].target	= (Position_t) { HOUSE_X, HOUSE_Y };
	ghosts[2].type		= GHOSTTYPE_PINKY;

	ghosts[3].pos		= (Position_t) { HOUSE_X, HOUSE_Y };
	ghosts[3].dir		= (Direction_t) { 1, 0 };
	ghosts[3].target	= (Position_t) { HOUSE_X, HOUSE_Y };
	ghosts[3].type		= GHOSTTYPE_CLYDE;
}

void drawGhosts  (void) {
	for (int i = 0; i < GHOST_AMOUNT; ++i) {
		Color color;

		switch (ghosts[i].type) {
			case GHOSTTYPE_BLINKY: color = BLINKY_COLOR; break;
			case GHOSTTYPE_INKY  : color = INKY_COLOR;   break;
			case GHOSTTYPE_PINKY : color = PINKY_COLOR;  break;
			case GHOSTTYPE_CLYDE : color = CLYDE_COLOR;  break;
		}

		DrawCircle(ghosts[i].pos.x + TILE_SIZE / 2, ghosts[i].pos.y + TILE_SIZE / 2, TILE_SIZE / 3, color);
	}
}

void updateGhosts(void) {

}