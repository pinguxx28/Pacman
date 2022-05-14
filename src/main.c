#include "raylib.h"
#include "consts.h"
#include "map.h"
#include "pacman.h"
#include "ghost.h"

int main(void)
{
	/*  Initialize game engine  */
	InitWindow(DISP_WIDTH, DISP_HEIGHT, "raylib [core] example - keyboard input");
	SetTargetFPS(FPS);

	/*  Initialize objects  */
	initMap();
	initPacman();
	initGhosts();

	while (!WindowShouldClose())
	{
		/*  Update  */
		updatePacman();
		updateGhosts();

		/*  Draw */
		BeginDrawing();

			ClearBackground(BLACK);
			drawPacman();
			drawMap();
			drawGhosts();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
