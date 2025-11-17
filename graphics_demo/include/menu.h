#ifndef MENU_H
#define MENU_H

#define DELAY 1.3f

void innitPrintMenuText();
void mainMenu();
void printSoundMenu(int x); //x takes in which text layer text to highlight 
void soundMenu();
void selectedSong();
void playSecretSong();

extern struct game gameStatus;

#endif