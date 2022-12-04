#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#define SAVE1 "save1.bin"
#define SAVE2 "save2.bin"
#define SAVE3 "save3.bin"

extern char g_save_file[10];

int fileExists(char file_name[]);
void saveCreate(char file_name[]);
void saveDelete(char file_name[]);
char* saveName(char file_name[], char alt[]);

#endif // FILEMANAGER_H