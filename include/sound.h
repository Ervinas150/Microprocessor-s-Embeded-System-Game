#ifndef SOUND_H
#define SOUND_H

#include <stdint.h>
void playNote(uint32_t Freq);
void initSound(void);

void mute();
void playLose();
void playWin();
void playGameMusic();
void playMainMenu();

#endif