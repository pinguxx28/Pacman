#include "raylib.h"
#include "consts.h"
#include "map.h"
#include "pacman.h"

int main(void)
{
	/*  Initialize game engine  */
	InitWindow(DISP_WIDTH, DISP_HEIGHT, "raylib [core] example - keyboard input");
	SetTargetFPS(15);

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
			drawMap();
			drawPacman();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
