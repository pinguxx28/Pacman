#include "raylib.h"
#include "consts.h"
#include "map.h"
#include "pacman.h"

int main(void)
{
	/*  Initialize game engine  */
	InitWindow(DISP_WIDTH, DISP_HEIGHT, "raylib [core] example - keyboard input");
	SetTargetFPS(FPS);

	/*  Initialize objects  */
	initMap();
	initPacman();

	while (!WindowShouldClose())
	{
		/*  Update  */
		updatePacman();

		/*  Draw */
		BeginDrawing();

			ClearBackground(BLACK);
			drawPacman();
			drawMap();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
