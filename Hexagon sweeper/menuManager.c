#include "menuManager.h"

#include "programManager.h"
#include "fileManager.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

MenuPage* g_menu_pages = NULL;

void initMenuData() {
	g_menu_pages = calloc(E_MENU_PAGE_END, sizeof(*g_menu_pages));

	if (g_menu_pages != NULL) {
		// initialize main menu page
		g_menu_pages[MAIN].capacity = 2;
		g_menu_pages[MAIN].element = calloc(g_menu_pages[MAIN].capacity, sizeof(MenuElement));

		if (g_menu_pages[MAIN].element != NULL) {
			strcpy(g_menu_pages[MAIN].element[0].name, "Load game");
			g_menu_pages[MAIN].element[0].type = PAGE_TRANSFER;
			g_menu_pages[MAIN].element[0].page = LOAD_GAME;

			strcpy(g_menu_pages[MAIN].element[1].name, "Quit");
			g_menu_pages[MAIN].element[1].type = FUNC_RUNNER;
			g_menu_pages[MAIN].element[1].func = QUIT;
		}

		// initialize load game menu page
		g_menu_pages[LOAD_GAME].capacity = 5;
		g_menu_pages[LOAD_GAME].element = calloc(g_menu_pages[LOAD_GAME].capacity, sizeof(MenuElement));

		if (g_menu_pages[LOAD_GAME].element != NULL) {
			strcpy(g_menu_pages[LOAD_GAME].element[0].name, saveName(SAVE1, "New game"));
			g_menu_pages[LOAD_GAME].element[0].type = FUNC_RUNNER;
			g_menu_pages[LOAD_GAME].element[0].func = SAVE_CREATE_1;

			strcpy(g_menu_pages[LOAD_GAME].element[1].name, saveName(SAVE2, "New game"));
			g_menu_pages[LOAD_GAME].element[1].type = FUNC_RUNNER;
			g_menu_pages[LOAD_GAME].element[1].func = SAVE_CREATE_2;

			strcpy(g_menu_pages[LOAD_GAME].element[2].name, saveName(SAVE3, "New game"));
			g_menu_pages[LOAD_GAME].element[2].type = FUNC_RUNNER;
			g_menu_pages[LOAD_GAME].element[2].func = SAVE_CREATE_3;

			strcpy(g_menu_pages[LOAD_GAME].element[3].name, "Delete save");
			g_menu_pages[LOAD_GAME].element[3].type = PAGE_TRANSFER;
			g_menu_pages[LOAD_GAME].element[3].page = DELETE_SAVE;

			strcpy(g_menu_pages[LOAD_GAME].element[4].name, "Back");
			g_menu_pages[LOAD_GAME].element[4].type = PAGE_TRANSFER;
			g_menu_pages[LOAD_GAME].element[4].page = MAIN;
		}

		// initialize delete save menu page
		g_menu_pages[DELETE_SAVE].capacity = 4;
		g_menu_pages[DELETE_SAVE].element = calloc(g_menu_pages[DELETE_SAVE].capacity, sizeof(MenuElement));

		if (g_menu_pages[DELETE_SAVE].element != NULL) {
			strcpy(g_menu_pages[DELETE_SAVE].element[0].name, saveName(SAVE1, "--------"));
			g_menu_pages[DELETE_SAVE].element[0].type = FUNC_RUNNER;
			g_menu_pages[DELETE_SAVE].element[0].func = SAVE_DELETE_1;

			strcpy(g_menu_pages[DELETE_SAVE].element[1].name, saveName(SAVE2, "--------"));
			g_menu_pages[DELETE_SAVE].element[1].type = FUNC_RUNNER;
			g_menu_pages[DELETE_SAVE].element[1].func = SAVE_DELETE_2;

			strcpy(g_menu_pages[DELETE_SAVE].element[2].name, saveName(SAVE3, "--------"));
			g_menu_pages[DELETE_SAVE].element[2].type = FUNC_RUNNER;
			g_menu_pages[DELETE_SAVE].element[2].func = SAVE_DELETE_3;

			strcpy(g_menu_pages[DELETE_SAVE].element[3].name, "Back");
			g_menu_pages[DELETE_SAVE].element[3].type = PAGE_TRANSFER;
			g_menu_pages[DELETE_SAVE].element[3].page = LOAD_GAME;
		}
	}
}

void freeMenuData() {
	if (g_menu_pages != NULL) {
		for (int i = 0; i < E_MENU_PAGE_END; ++i) {
			if (g_menu_pages[i].element != NULL) {
				free(g_menu_pages[i].element);
			}
		}
		free(g_menu_pages);
	}
}

void displayMenuPage(EMenuPage page) {
	switch (page) {
	case MAIN:
		printf("-----MAIN MENU-----\n\n");
		break;
		
	case LOAD_GAME:
		printf("-----LOAD GAME-----\n\n");
		break;

	case DELETE_SAVE:
		printf("----DELETE SAVE----\n\n");
		break;
	}

	for (int i = 0; i < g_menu_pages[page].capacity; ++i) {
		printf("%4d. %s\n", i + 1, g_menu_pages[page].element[i].name);
	}
	printf("\n-------------------\n\n");

	printf("Select element: ");
}

void selectMenuElement(EMenuPage* page) {
	int element;
	scanf("%d", &element);

	switch (g_menu_pages[*page].element[element - 1].type) {
		case FUNC_RUNNER: 
			runMenuFunction(g_menu_pages[*page].element[element - 1].func, element - 1);
			break;

		case PAGE_TRANSFER: 
			*page = g_menu_pages[*page].element[element - 1].page;
			break;
	}
}

void renameMenuElement(char name[], EMenuPage page, int element) {
	strcpy(g_menu_pages[page].element[element].name, name);
}

void runMenuFunction(EMenuFunc func, int element) {
	switch (func) {
		// main menu
	case QUIT:
		quit();
		break;

		// load game menu
	case SAVE_CREATE_1:
		saveCreate(SAVE1);
		renameMenuElement(saveName(SAVE1, "New game"), LOAD_GAME, element);
		renameMenuElement(saveName(SAVE1, "--------"), DELETE_SAVE, element);
		break;
	case SAVE_CREATE_2:
		saveCreate(SAVE2);
		renameMenuElement(saveName(SAVE2, "New game"), LOAD_GAME, element);
		renameMenuElement(saveName(SAVE2, "--------"), DELETE_SAVE, element);
		break;
	case SAVE_CREATE_3:
		saveCreate(SAVE3);
		renameMenuElement(saveName(SAVE3, "New game"), LOAD_GAME, element);
		renameMenuElement(saveName(SAVE3, "--------"), DELETE_SAVE, element);
		break;

		// delete save menu
	case SAVE_DELETE_1:
		saveDelete(SAVE1);
		renameMenuElement(saveName(SAVE1, "New game"), LOAD_GAME, element);
		renameMenuElement(saveName(SAVE1, "--------"), DELETE_SAVE, element);
		break;
	case SAVE_DELETE_2:
		saveDelete(SAVE2);
		renameMenuElement(saveName(SAVE2, "New game"), LOAD_GAME, element);
		renameMenuElement(saveName(SAVE2, "--------"), DELETE_SAVE, element);
		break;
	case SAVE_DELETE_3:
		saveDelete(SAVE3);
		renameMenuElement(saveName(SAVE2, "New game"), LOAD_GAME, element);
		renameMenuElement(saveName(SAVE2, "--------"), DELETE_SAVE, element);
		break;
	}
}