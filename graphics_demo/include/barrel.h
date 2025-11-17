#ifndef BARREL_H
#define BARREL_H

#define BARRELLIMIT 11
#define XBARREL 5
#define YBARREL 5

void barrelInnit();//start sequence of barrels
void barrelMovement(int speed);//movement of barrels
void createBarrels(int);//creates a barrel, takes in index
void didReachedEnd();//check if barrel reaches the end
void spawnBarrels();//spawn more barrels if empty slot available
void clearBarrels(); //created var becomes 0 on all barrels


extern struct barrels barrelSprite[];
extern struct chara charaSprite;
extern struct game gameStatus;

#endif