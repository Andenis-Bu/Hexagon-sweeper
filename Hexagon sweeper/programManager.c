#include "programManager.h"

#include <windows.h>
#include <stdio.h>

int const g_dellay = 1 / FPS * 1000;

int g_program_state;
ERoom g_room_state;

void clearConsole() {
	system("cls");
}

void dellayExe() {
	Sleep(g_dellay);
}

void roomGoto(ERoom room) {
	g_room_state = room;
}

void quit() {
	g_program_state = 0;
	g_room_state = R_NONE;
}
