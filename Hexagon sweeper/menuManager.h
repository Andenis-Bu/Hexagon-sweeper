#ifndef MENUMANAGER_H
#define MENUMANAGER_H

// menu element type
typedef enum EMenuElementType {
	FUNC_RUNNER,
	PAGE_TRANSFER
} EMenuElementType;

// menu page to transfer to
typedef enum EMenuPage {
	MAIN,
	LOAD_GAME,
	DELETE_SAVE,
	E_MENU_PAGE_END
} EMenuPage;

// menu function to run
typedef enum EMenuFunc {
	// main menu
	ROOM_GOTO,
	QUIT,

	// load game menu
	SAVE_CREATE_1,
	SAVE_CREATE_2,
	SAVE_CREATE_3,

	// delete save menu
	SAVE_DELETE_1,
	SAVE_DELETE_2,
	SAVE_DELETE_3
} EMenuFunc;

typedef struct MenuElement {
	char name[30];						// menu element name			
	EMenuElementType type;				// menu element type			

	EMenuPage page;						// menu page to transfer to
	EMenuFunc func;						// menu function to run
} MenuElement;

typedef struct MenuPage {
	int capacity;						// menu page element capacity
	MenuElement* element;				// array of every menu page element structure

} MenuPage;

extern MenuPage* g_menu_pages;			// array of every menu page structure

void initMenuData();
void freeMenuData();

void displayMenuPage(EMenuPage page);
void selectMenuElement(EMenuPage* page);
void renameMenuElement(char name[], EMenuPage page, int element);
void runMenuFunction(EMenuFunc func, int element);


#endif // MENUMANAGER_H