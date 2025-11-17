
#ifndef METAL_H
#define METAL_H


void metalSetup();


int isOnPipe(int, int,int,int); //checks if we are ON a pipe
int isOnMetalCords(int, int); //checks if we are on any kind of metal (used to make other functions shorter)
int isInsideLayer1(int,int);
int isInsideLayer2(int,int);
int isInsideLayer3(int,int);


int isHittingWall(int,int);//checks if we are HITTING the pipe
int isCloseMain(uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t);
int isCloseLayer1(int,int);
int isCloseLayer2(int,int);
int isCloseLayer3(int,int);

#endif