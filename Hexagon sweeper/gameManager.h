#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

typedef enum ECellElement {
	EMPTY,
	FLAG
} ECellElement;

typedef struct GameData {
	int row, column;
	ECellElement mine_grid[15][8];
	ECellElement game_grid[15][8];
} GameData;

extern GameData g_game_data;

void initGameData();
void displayGameGrid();
void selectGameElement();

#endif // GAMEMANAGER_H