#include "map.h"

/*  Variables  */
int map[MAP_HEIGHT][MAP_WIDTH];
int tempMap[MAP_HEIGHT][MAP_WIDTH] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1 },
	{ 1,3,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,3,1 },
	{ 1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
	{ 1,2,1,1,2,1,2,1,1,1,1,1,2,1,2,1,1,2,1 },
	{ 1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1 },
	{ 1,1,1,1,2,1,1,1,0,1,0,1,1,1,2,1,1,1,1 },
	{ 0,0,0,1,2,1,0,0,0,0,0,0,0,1,2,1,0,0,0 },
	{ 1,1,1,1,2,1,0,1,1,1,1,1,0,1,2,1,1,1,1 },
	{ 0,0,0,0,2,0,0,1,0,0,0,1,0,0,0,0,0,0,0 },
	{ 1,1,1,1,2,1,0,1,1,1,1,1,0,1,2,1,1,1,1 },
	{ 0,0,0,1,2,1,0,0,0,0,0,0,0,1,2,1,0,0,0 },
	{ 1,1,1,1,2,1,0,1,1,1,1,1,0,1,2,1,1,1,1 },
	{ 1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1 },
	{ 1,2,1,1,2,1,1,1,2,1,2,1,1,1,2,1,1,2,1 },
	{ 1,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,2,2,1 },
	{ 1,1,2,1,2,1,2,1,1,1,1,1,2,1,2,1,2,1,1 },
	{ 1,2,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1 },
	{ 1,2,1,1,1,1,1,1,2,1,2,1,1,1,1,1,1,2,1 },
	{ 1,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};



/*  Sub  functions  */
/*  Main functions  */
void initMap() {
	for (int y = 0; y < MAP_HEIGHT; ++y)
		for (int x = 0; x < MAP_WIDTH; ++x)
			map[y][x] = tempMap[y][x];
}

void drawMap() {
	for (int y = 0; y < MAP_HEIGHT; ++y)
		for (int x = 0; x < MAP_WIDTH; ++x)
			if (map[y][x] == 3) {
				DrawCircle((x + 0.5) * TILE_SIZE, (y + 0.5) * TILE_SIZE, TILE_SIZE / 4, YELLOW);
			} else if (map[y][x] == 2) {
				DrawCircle((x + 0.5) * TILE_SIZE, (y + 0.5) * TILE_SIZE, TILE_SIZE / 10, YELLOW);
			} else if (map[y][x] == 1) {
				/* Get connecting walls */
				bool rightWall, leftWall, downWall, upWall;
				if (x >= MAP_WIDTH - 1 || map[y][x + 1] == 1) rightWall = true;
				else rightWall = false;
				if (x <= 0 || map[y][x - 1] == 1) leftWall = true;
				else leftWall = false;
				if (y >= MAP_HEIGHT - 1 || map[y + 1][x] == 1) downWall = true;
				else downWall = false;
				if (y <= 0 || map[y - 1][x] == 1) upWall = true;
				else upWall = false;

				float ro = 0.4;

				/* Right single connected to top and bottom */
				if (upWall && downWall && !rightWall) DrawLineEx(
					(Vector2) { (x + 1) * TILE_SIZE, (y + 0) * TILE_SIZE },
					(Vector2) { (x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE},
					3, BLUE);
				
				/* Left  single connected to top and bottom */
				if (upWall && downWall && !leftWall ) DrawLineEx(
					(Vector2) { (x + 0) * TILE_SIZE, (y + 0) * TILE_SIZE },
					(Vector2) { (x + 0) * TILE_SIZE, (y + 1) * TILE_SIZE },
					3, BLUE);
				
				/* Down  single connected to right and left */
				if (rightWall && leftWall && !downWall)  DrawLineEx(
					(Vector2) { (x + 0) * TILE_SIZE, (y + 1) * TILE_SIZE },
					(Vector2) { (x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE},
					3, BLUE);
				
				/* Up    single connected to right and left */
				if (rightWall && leftWall && !upWall  )  DrawLineEx(
					(Vector2) { (x + 0) * TILE_SIZE, (y + 0) * TILE_SIZE },
					(Vector2) { (x + 1) * TILE_SIZE, (y + 0) * TILE_SIZE},
					3, BLUE);




				/*  Single bottom arc  */
				if (!downWall && !leftWall && !rightWall && upWall) {
					DrawLineEx(
						(Vector2) { (x + 1) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1 - ro) * TILE_SIZE},
						3, BLUE);
					DrawLineEx(
						(Vector2) { (x + 0) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1 - ro) * TILE_SIZE },
						3, BLUE);
					DrawLineBezierCubic(
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1 - ro) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1 - ro) * TILE_SIZE },
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE},
						3, BLUE);
				}

				/*  Single top arc  */
				if (downWall && !leftWall && !rightWall && !upWall) {
					DrawLineEx(
						(Vector2) { (x + 1) * TILE_SIZE, (y + ro) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE},
						3, BLUE);
					DrawLineEx(
						(Vector2) { (x + 0) * TILE_SIZE, (y + ro) * TILE_SIZE },
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1) * TILE_SIZE },
						3, BLUE);
					DrawLineBezierCubic(
						(Vector2) { (x + 0) * TILE_SIZE, (y + ro) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + ro) * TILE_SIZE },
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1 - 1) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1 - 1) * TILE_SIZE },
						3, BLUE);
				}

				/*  Single right arc  */
				if (!downWall && !upWall && leftWall && !rightWall) {
					DrawLineEx(
						(Vector2) { (x + 0) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 1 - ro) * TILE_SIZE, (y + 0) * TILE_SIZE},
						3, BLUE);
					DrawLineEx(
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1) * TILE_SIZE },
						(Vector2) { (x + 1 - ro) * TILE_SIZE, (y + 1) * TILE_SIZE},
						3, BLUE);
					DrawLineBezierCubic(
						(Vector2) { (x + 1 - ro) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 1 - ro) * TILE_SIZE, (y + 1) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE},
						3, BLUE);
				}

				/*  Single left arc  */
				if (!downWall && !upWall && !leftWall && rightWall) {
					DrawLineEx(
						(Vector2) { (x + ro) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 0) * TILE_SIZE},
						3, BLUE);
					DrawLineEx(
						(Vector2) { (x + ro) * TILE_SIZE, (y + 1) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE},
						3, BLUE);
					DrawLineBezierCubic(
						(Vector2) { (x + ro) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + ro) * TILE_SIZE, (y + 1) * TILE_SIZE },
						(Vector2) { (x + 1 - 1) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 1 - 1) * TILE_SIZE, (y + 1) * TILE_SIZE},
						3, BLUE);
				}




				/* Bottom right arc */
				if (!downWall && !rightWall && leftWall && upWall) {
					DrawLineEx(
						(Vector2) { (x + 1) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1 - ro) * TILE_SIZE},
						3, BLUE);
					DrawLineEx(
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1) * TILE_SIZE },
						(Vector2) { (x + 1 - ro) * TILE_SIZE, (y + 1) * TILE_SIZE},
						3, BLUE);
					DrawLineBezierQuad(
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1 - ro) * TILE_SIZE },
						(Vector2) { (x + 1 - ro) * TILE_SIZE, (y + 1) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE },
						3, BLUE);
				}

				/* Bottom left arc */
				if (!downWall && rightWall && !leftWall && upWall) {
					DrawLineEx(
						(Vector2) { (x + 0) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1 - ro) * TILE_SIZE },
						3, BLUE);
					DrawLineEx(
						(Vector2) { (x + ro) * TILE_SIZE, (y + 1) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE},
						3, BLUE);
					DrawLineBezierQuad(
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1 - ro) * TILE_SIZE },
						(Vector2) { (x + ro) * TILE_SIZE, (y + 1) * TILE_SIZE },
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1) * TILE_SIZE },
						3, BLUE);
				}

				/* Top right arc */
				if (downWall && !rightWall && leftWall && !upWall) {
					DrawLineEx(
						(Vector2) { (x + 0) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 1 - ro) * TILE_SIZE, (y + 0) * TILE_SIZE},
						3, BLUE);
					DrawLineEx(
						(Vector2) { (x + 1) * TILE_SIZE, (y + ro) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE},
						3, BLUE);
					DrawLineBezierQuad(
						(Vector2) { (x + 1 - ro) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + ro) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 0) * TILE_SIZE },
						3, BLUE);
				}
				
				/* Top left arc */
				if (downWall && rightWall && !leftWall && !upWall) {
					DrawLineEx(
						(Vector2) { (x + ro) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 1) * TILE_SIZE, (y + 0) * TILE_SIZE},
						3, BLUE);
					DrawLineEx(
						(Vector2) { (x + 0) * TILE_SIZE, (y + ro) * TILE_SIZE },
						(Vector2) { (x + 0) * TILE_SIZE, (y + 1) * TILE_SIZE },
						3, BLUE);
					DrawLineBezierQuad(
						(Vector2) { (x + 0) * TILE_SIZE, (y + ro) * TILE_SIZE },
						(Vector2) { (x + ro) * TILE_SIZE, (y + 0) * TILE_SIZE },
						(Vector2) { (x + 0) * TILE_SIZE, (y + 0) * TILE_SIZE },
						3, BLUE);
				}
			}
}