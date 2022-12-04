#include "gameManager.h"

#include "programManager.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

GameData g_game_data;

void initGameData() {
	
	g_game_data.row = 15;
	g_game_data.column = (g_game_data.row + 1) / 2;
	
	for (int i = 0; i < g_game_data.row; ++i) {
			for (int j = 0; j < g_game_data.column; ++j) {
				
			}
	}
	
	srand(time(NULL));
	for (int i = 0; i < g_game_data.row; ++i) {
			for (int j = 0; j < g_game_data.column; ++j) {
				if (rand() % 5 == 0) {
					g_game_data.game_grid[i][j] = FLAG;
				}
				else {
					g_game_data.game_grid[i][j] == EMPTY;
				}
			}
	}
}

void displayGameGrid() {
	// print top row of letters
	printf("     ");
	for (int i = 0; i < g_game_data.row + 1; ++i) {
		if (i % 2 == 0) {
			printf("%c ", 'A' + i);
		}
		else {
			printf("%c ", 'a' + i);
		}
	}
	printf("\n");

	// print game board
	char cell_element;
	for (int i = 0; i < g_game_data.row; ++i) {
		printf(" %2d|", i);
		for (int j = 0; j < g_game_data.column; ++j) {
			switch (g_game_data.game_grid[i][j]) {
			case EMPTY:
				cell_element = ' ';
				break;

			case FLAG:
				cell_element = 'F';
				break;
			}

			if (i % 2 == 0) {
				if (j == 0) {
					printf(">-<%c>", cell_element);
				}
				else {
					printf("-<%c>", cell_element);
				}
			}
			else {
				if (j == g_game_data.column - 1) {
					printf("<%c>-<", cell_element);
				}
				else {
					printf("<%c>-", cell_element);
				}
				
			}
		}
		printf("|%-2d\n", i);
	}

	// print bottom row of letters
	printf("     ");
	for (int i = 0; i < g_game_data.row + 1; ++i) {
		if (i % 2 == 0) {
			printf("%c ", 'A' + i);
		}
		else {
			printf("%c ", 'a' + i);
		}
	}
	printf("\n");

	printf("\nSelect element: ");
}

void selectGameElement() {
	int element;
	int letter;
	scanf("%d%c", &element, &letter);
}