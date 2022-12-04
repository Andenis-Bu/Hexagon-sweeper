#include "fileManager.h"

#include "programManager.h"
#include "gameManager.h"

#include <stdio.h>
#include <string.h>

char g_save_file[10];

int fileExists(char file_name[]) {
	FILE* f_ptr = fopen(file_name, "rb");
	if (f_ptr != NULL) {
		fclose(f_ptr);
		return 1;
	}

	return 0;
}

void saveCreate(char file_name[]) {
	clearConsole();
	char save_name[10];
	
	// if save file doesn't exists create its
	if (!fileExists(file_name)) {
		printf("Enter file name: ");
		scanf("%s", save_name);

		// create save file
		FILE* f_ptr = fopen(file_name, "wb");
		if (f_ptr != NULL) {
			fwrite(save_name, sizeof(save_name), 1, f_ptr);
			initGameData();
			fwrite(&g_game_data, sizeof(g_game_data), 1, f_ptr);
			fclose(f_ptr);

			strcpy(g_save_file, file_name);
			roomGoto(R_GAME);
		}
	}

	// if save file exists load it and move to game room
	if (fileExists(file_name)) {
		// load save file
		strcpy(g_save_file, file_name);
		FILE* f_ptr = fopen(file_name, "rb");
		if (f_ptr != NULL) {
			fread(save_name, sizeof(save_name), 1, f_ptr);
			fread(&g_game_data, sizeof(g_game_data), 1, f_ptr);
			fclose(f_ptr);

			strcpy(g_save_file, file_name);
			roomGoto(R_GAME);
		}
	}
}

void saveDelete(char file_name[]) {
	if (fileExists(file_name)) {
		remove(file_name);
	}
}

char* saveName(char file_name[], char alt[]) {
	char save_name[10];

	FILE* f_ptr = fopen(file_name, "rb");
	if (f_ptr != NULL) {
		fread(save_name, 1, sizeof(file_name), f_ptr);
		fclose(f_ptr);

		return save_name;
	}

	return alt;
}