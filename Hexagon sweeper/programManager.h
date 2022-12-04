#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#define FPS 60	
extern const int g_dellay;

typedef enum ERoom {
	R_MENU,
	R_GAME,
	R_NONE
} ERoom;

extern int g_program_state;
extern ERoom g_room_state;

void clearConsole();
void dellayExe();
void roomGoto(ERoom room);
void quit();

#endif // PROGRAMMANAGER_H
