#ifndef CHARA_H
#define CHARA_H

#include <stm32f031x6.h>

#define CHAR_X 6
#define CHAR_Y 10


void charaMovement();
void charaInnit();
void jumpPhysics();


extern struct chara charaSprite;

#endif