#ifndef __MAP_H
#define __MAP_H
#include "raylib.h"
#include "consts.h"

/*  Variables  */
extern int map[MAP_HEIGHT][MAP_WIDTH];

/*  Sub  functions  */
/*  Main functions  */
void initMap();
void drawMap();

#endif