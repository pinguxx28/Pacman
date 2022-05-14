#include "pacman.h"

Pacman_t pacman;

/*  Sub  functions  */
void handleInput  (void) {
	if (IsKeyDown(KEY_RIGHT)) pacman.qdir = (Direction_t) { 1, 0 };
	if (IsKeyDown(KEY_LEFT )) pacman.qdir = (Direction_t) {-1, 0 };
	if (IsKeyDown(KEY_DOWN )) pacman.qdir = (Direction_t) { 0, 1 };
	if (IsKeyDown(KEY_UP   )) pacman.qdir = (Direction_t) { 0,-1 };
}

void setQueueDir  (void) {
	exit_func(pacman.pos.x % TILE_SIZE || pacman.pos.y % TILE_SIZE);
	exit_func(map[pacman.pos.y / TILE_SIZE + pacman.qdir.y][pacman.pos.x / TILE_SIZE + pacman.qdir.x] == 1);

	pacman.dir = pacman.qdir;

	if (pacman.dir.x) pacman.facing = abs(pacman.dir.x - 2);
	if (pacman.dir.y) pacman.facing = abs(pacman.dir.y - 1);
}

void movePacman   (void) {
	pacman.pos.x += pacman.dir.x * PACMAN_MOVEMENT_SPEED;
	pacman.pos.y += pacman.dir.y * PACMAN_MOVEMENT_SPEED;

	exit_func(pacman.pos.x % TILE_SIZE || pacman.pos.y % TILE_SIZE);
	exit_func(pacman.pos.x == 0 || pacman.pos.x / TILE_SIZE == MAP_WIDTH  - 1);
	exit_func(pacman.pos.y == 0 || pacman.pos.y / TILE_SIZE == MAP_HEIGHT - 1);

	if (map[pacman.pos.y / TILE_SIZE + pacman.dir.y][pacman.pos.x / TILE_SIZE + pacman.dir.x] == 1)
		pacman.dir = (Direction_t) { 0, 0 };
}

void pacmanFrames (void) {
	pacman.anim_frame += pacman.frame_inc;

	if (pacman.anim_frame > PACMAN_MAXFRAME) pacman.frame_inc *= -1;
	if (pacman.anim_frame < PACMAN_MINFRAME) pacman.frame_inc *= -1;
}

void wrapScreen   (void) {
	if (pacman.pos.x + TILE_SIZE / 2 < 0)          pacman.pos.x = DISP_WIDTH - TILE_SIZE / 2;
	if (pacman.pos.x + TILE_SIZE / 2 > DISP_WIDTH) pacman.pos.x = 0          - TILE_SIZE / 2;

	if (pacman.pos.y + TILE_SIZE / 2 < 0)           pacman.pos.y = DISP_HEIGHT - TILE_SIZE / 2;
	if (pacman.pos.y + TILE_SIZE / 2 > DISP_HEIGHT) pacman.pos.y = 0           - TILE_SIZE / 2;
}

void collectCoins (void) {
	exit_func(pacman.pos.x % TILE_SIZE || pacman.pos.y % TILE_SIZE);

	if (map[pacman.pos.y / TILE_SIZE][pacman.pos.x / TILE_SIZE] == 2) {
		pacman.score += 10;
		map[pacman.pos.y / TILE_SIZE][pacman.pos.x / TILE_SIZE] = 0;
	}
}

void collectPellet(void) {
	exit_func(pacman.pos.x % TILE_SIZE || pacman.pos.y % TILE_SIZE);

	if (map[pacman.pos.y / TILE_SIZE][pacman.pos.x / TILE_SIZE] == 3) {
		pacman.pellet_timer = FPS * 10;
		pacman.score += 40;
		map[pacman.pos.y / TILE_SIZE][pacman.pos.x / TILE_SIZE] = 0;
	}
}

void updatePellet (void) {
	exit_func(!pacman.pellet_timer);

	pacman.pellet_timer--;
}

void updateScore  (void) {
	for (int i = 0; i < 5; i++) {
        long diff = 1 << i;

        if (pacman.score_disp <= (pacman.score - diff))
            pacman.score_disp += diff;
    }
}

void drawScore    (void) {
	char score_text[8];
	sprintf(score_text, "%06d\n", pacman.score_disp);

	DrawText(score_text, 4, 4, 24, WHITE);
}



/*  Main functions */
void initPacman  (void) {
	pacman.pos			= (Position_t)  { PACMAN_START_X, PACMAN_START_Y };
	pacman.dir			= (Direction_t) { 0, 0 };
	pacman.qdir		 	= (Direction_t) { 0, 0 };
	pacman.facing    	= 3;
	pacman.anim_frame	= 0;
	pacman.frame_inc 	= PACMAN_FRAMEINC;
	pacman.score	 	= 0;
	pacman.score_disp	= 0;
}

void drawPacman  (void) {
	DrawCircle(pacman.pos.x + TILE_SIZE / 2, pacman.pos.y + TILE_SIZE / 2, PACMAN_RADIUS,
		(pacman.pellet_timer % 2 == 0) ? PACMAN_COLOR : ORANGE);

	DrawCircleSector(
		(Vector2) { pacman.pos.x + TILE_SIZE / 2, pacman.pos.y + TILE_SIZE / 2 },
		PACMAN_RADIUS, pacman.facing * 90 - pacman.anim_frame, pacman.facing * 90 + pacman.anim_frame, 45, BLACK);

	drawScore();
}

void updatePacman(void) {
	handleInput  ();
	setQueueDir  ();
	movePacman   ();
	pacmanFrames ();
	wrapScreen   ();
	collectCoins ();
	collectPellet();
	updatePellet ();
	updateScore  ();
}