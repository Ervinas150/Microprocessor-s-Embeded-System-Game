
//#define SCREEN_WIDTH 128
//#define SCREEN_HEIGHT 160

#ifndef MAIN_H
#define MAIN_H


#include <stm32f031x6.h>


#define DIFFERENCE_BLOCKS 12 //this is how much we (-) from the range


void initClock(void);
void initSysTick(void);
void SysTick_Handler(void);
void delay(volatile uint32_t dly);
void setupIO();
int isInside(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint16_t px, uint16_t py);
void enablePullUp(GPIO_TypeDef *Port, uint32_t BitNumber);
void pinMode(GPIO_TypeDef *Port, uint32_t BitNumber, uint32_t Mode);

int winCheck();
int flip(short);//flips 1 to 0, 0 to 1a
int signFlip(int);//turns negatives to positives, vice versa


//SPRITES
extern const uint16_t trophy[];
extern const uint16_t barrel[];
extern const uint16_t metal[];
extern const uint16_t metalX[];
extern const uint16_t metalY[];
extern const uint16_t main_chara[];
extern const uint16_t main_charaJump[];
extern const uint16_t deco1[];
extern const uint16_t deco2[];
extern const uint16_t deco3[];
extern const uint16_t dg1[];


//time
extern volatile uint32_t milliseconds;

//MUSIC
extern uint32_t *background_tune_notes;
extern uint32_t *background_tune_times;
extern uint32_t background_tune_note_count;
extern uint32_t background_repeat_tune;
extern const uint32_t menu[];
extern const uint32_t menu_times[];
extern const uint32_t gameMusic[];
extern const uint32_t gameTimes[];
extern const uint32_t loseMusic[];
extern const uint32_t loseTimes[];
extern const uint32_t winMusic[];
extern const uint32_t winTimes[];
extern const uint32_t empty_note[];
extern const uint32_t empty_times[];
extern const uint32_t menu[];
extern const uint32_t menu_times[];
extern const uint32_t gameMusic[];
extern const uint32_t gameTimes[];
extern const uint32_t loseMusic[];
extern const uint32_t loseTimes[];
extern const uint32_t winMusic[];
extern const uint32_t winTimes[];



//SPRITE VARS
struct barrels {
	short created;
	uint16_t oldx;
	uint16_t oldy;
	uint16_t x;
	uint16_t y;
    short RLount;
    short barrelMoved;
	short barrelFalling;
};

struct chara {
	uint16_t x;
	uint16_t y;
	uint16_t oldx;
	uint16_t oldy;
	short hinverted;
	short vinverted;
	short toggle;
	short hmoved;
	short vmoved;
	short falling;
	int hittingWall;
};

struct game {
	short gameStart;
	short soundtrackStart;
	short playerHit;
	int playerLives;
	short playerWon;
    short menuOption; //0 start game, 1 soundtracks
    short menuConfirm; //-1 go back, 0 nothing, 1 go forward
};

#endif