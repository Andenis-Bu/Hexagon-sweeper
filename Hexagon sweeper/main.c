#include "programManager.h"
#include "menuManager.h"
#include "gameManager.h"

#include <windows.h>
#include <stdio.h>

int main() {
	#ifndef _WIN32	
	printf("Incompatible operating system detected.\n");
	exit(EXIT_FAILURE);
	#endif
	
	g_program_state = 1;	
	g_room_state = R_MENU;

	int r_menu_create = 1;
	int r_game_create = 1;

	EMenuPage page = MAIN;

	// Program loop
	while (g_program_state) {	

		// Menu loop
		while (g_room_state == R_MENU) {
			// create event
			if (r_menu_create) {
				initMenuData();
				
				r_menu_create = 0;
			}

			// draw GUI event
			clearConsole();
			displayMenuPage(page);

			// step event
			selectMenuElement(&page);


			dellayExe();
		} 
		
		// Game loop
		while (g_room_state == R_GAME) {
			// create event
			if (r_game_create) {
				

				r_game_create = 0;
			}

			// draw GUI event
			clearConsole();
			displayGameGrid();

			// step event
			selectGameElement();
			

			dellayExe();
		}
	}

	// Program cleanup event
	clearConsole();
	if (r_menu_create == 0) {
		freeMenuData();
	}
	if (r_game_create == 0) {

	}

	return 0;
} 