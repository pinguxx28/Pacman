#ifndef __PACMAN_H
#define __PACMAN_H
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "consts.h"
#include "map.h"

typedef struct {
	Position_t	pos;
	Direction_t	dir;
	Direction_t	qdir;
	uint8_t		facing;
	uint8_t		anim_frame;
	uint8_t     frame_inc;
	uint32_t	score;
	uint32_t	score_disp;
} Pacman_t;

extern Pacman_t pacman;

/*  Sub  functions  */
void handleInput  (void);
void setQueueDir  (void);
void movePacman   (void);
void pacmanFrames (void);
void wrapScreen   (void);
void collectCoins (void);
void updateScore  (void);
void drawScore    (void);

/*  Main functions  */
void initPacman	  (void);
void drawPacman	  (void);
void updatePacman (void);

#endif