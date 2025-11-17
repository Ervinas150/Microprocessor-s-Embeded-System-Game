#include "display.h"
#include "metal.h"
#include "main.h"
#include "serial.h"
#include "barrel.h"
#include "chara.h"
#include "menu.h"
#include "sound.h"
#include "musical_notes.h"

//GLOBAL VARIABLES
volatile uint32_t milliseconds;

const uint16_t trophy[] = 
{
	0,0,32517,24311,40743,32517,0,0,24311,40743,32517,24311,40743,32517,40743,40743,40743,0,32517,40743,40743,32517,0,40743,32517,0,32517,40743,40743,32517,0,40743,0,21818,32517,32517,32517,32517,32517,0,0,0,21818,0,0,32517,0,0,0,0,0,21818,21818,0,0,0,0,0,32517,32517,32517,32517,0,0
};

// const uint16_t barrel[] = 
// {
// 	0,0,31243,31243,31243,31243,31243,31243,0,0,0,31243,31243,57100,57100,57100,57100,31243,31243,0,31243,31243,57100,57100,23567,23567,57100,57100,31243,31243,31243,57100,57100,23567,23567,23567,23567,57100,57100,31243,31243,57100,23567,23567,23567,23567,23567,23567,57100,31243,31243,57100,23567,23567,23567,23567,23567,23567,57100,31243,31243,57100,57100,23567,23567,23567,23567,57100,57100,31243,31243,31243,57100,57100,23567,23567,57100,57100,31243,31243,0,31243,31243,57100,57100,57100,57100,31243,31243,0,0,0,31243,31243,31243,31243,31243,31243,0,0
// };

const uint16_t barrel[] = 
{
0,31772,31772,31772,0,31772,56094,56094,56094,31772,31772,56094,56094,56094,31772,31772,56094,56094,56094,31772,0,31772,31772,31772,0
};
const uint16_t metal[] =
{
    24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328,24328
};

const uint16_t metalX[] =
{
	0,20,40,60,80,100
};

const uint16_t metalY[] =
{
	155,150,145,120, 115, 110, 85,80,75,50,30
};

const uint16_t main_chara[] =
{
	37803,37803,37803,37803,37848,37848,37803,37803,37803,37848,0,37848,37803,37803,37848,37848,37848,37848,37803,37848,0,0,37848,37848,0,0,37848,37848,0,0,37848,33120,37848,37848,33120,37848,37848,0,33120,33120,0,0,0,0,33120,33120,0,0,0,33120,33120,33120,33120,0,37848,33120,0,0,33120,37848
};
const uint16_t main_charaJump[] =
{
	37803,37803,37803,37803,37848,37848,37803,37803,37803,37848,0,37848,37803,37803,37848,37848,37848,37848,37803,37848,0,0,37848,37848,33120,0,37848,37848,0,33120,33120,33120,33120,33120,33120,33120,0,0,33120,33120,0,0,0,0,33120,33120,0,0,0,33120,33120,33120,33120,0,37848,33120,0,0,33120,37848
};

const uint16_t donkeyKong[] = 
{
	0,0,0,0,0,0,0,0,28962,28962,28962,28962,0,0,0,0,0,0,0,0,0,0,0,28962,28962,28962,28962,28962,28962,28962,0,0,0,0,0,0,28962,28962,32273,28962,28962,28962,28962,28962,56461,56461,56461,0,0,0,0,28962,28962,28962,32273,28962,28962,56461,56461,28962,52322,0,0,0,0,0,28962,28962,28962,28962,32273,28962,28962,56461,56461,28962,24311,0,0,0,0,28962,28962,28962,28962,28962,28962,32273,28962,28962,56461,56461,56461,56461,28962,56461,0,28962,28962,28962,28962,28962,28962,28962,32273,56461,56461,56461,56461,56461,56461,56461,28962,28962,28962,28962,28962,28962,28962,28962,32273,56461,56461,0,56461,56461,56461,56461,28962,28962,28962,28962,28962,28962,28962,28962,28962,32273,56461,56461,0,0,0,0,28962,28962,28962,28962,19473,28962,28962,28962,28962,28962,56461,56461,56461,56461,56461,56461,28962,28962,28962,28962,19473,28962,28962,28962,28962,56461,32273,56461,56461,56461,56461,0,28962,28962,28962,19473,19473,28962,28962,28962,28962,56461,32273,32273,28962,28962,0,0,28962,28962,28962,28962,56461,28962,28962,28962,56461,56461,32273,32273,28962,28962,0,0,28962,28962,28962,28962,0,28962,28962,28962,28962,0,32273,32273,28962,28962,28962,0,28962,28962,28962,0,0,0,56461,28962,28962,0,0,32273,32273,28962,28962,0,56461,56461,56461,56461,0,56461,56461,56461,56461,0,0,32273,32273,56461,56461,0
};

struct barrels barrelSprite[BARRELLIMIT];
struct chara charaSprite;
struct game gameStatus;

void mainMenuLogic();
void soundTrackLogic();
void runMainGame();


//music vars
uint32_t *background_tune_notes;
uint32_t *background_tune_times;
uint32_t background_tune_note_count;
uint32_t background_repeat_tune;

const uint32_t menu[]={A3,D2,D3,D4,G4,G3,G2};
const uint32_t menu_times[]={500, 500, 500, 500, 500, 500, 1000};
const uint32_t gameMusic[] = {A3,A4,A5, G5,A5};
const uint32_t gameTimes[]={250, 250, 250, 500, 500};
const uint32_t loseMusic[] = {E5,E4,E2};
const uint32_t loseTimes[]={250, 750, 500};
const uint32_t winMusic[] = {A3,A4,A3};
const uint32_t winTimes[]={500, 500, 500};

const uint32_t empty_note[]={0};
const uint32_t empty_times[]={10};

int main()
{
	//system setup
	initClock();
	initSysTick();
	initSerial();
	setupIO();
	initSound();

	//forever running game
	while (1)
	{
		//start of game loop
		clear();
		mute();

		mainMenuLogic();//main menu logic ran here
	
		//out of menu, mute and clear whole screen
		mute();
		clear();

		//main game logic
		if(gameStatus.gameStart == 1)
		{
			runMainGame();
		}

		//if soundtrack selected
		if(gameStatus.soundtrackStart == 1)
		{
			soundTrackLogic();
		}

	}
	return 0;
}
void initSysTick(void)
{
	SysTick->LOAD = 48000;
	SysTick->CTRL = 7;
	SysTick->VAL = 10;
	__asm(" cpsie i "); // enable interrupts
}

void SysTick_Handler(void) {
    milliseconds++;
    static int index = 0;
    static int current_note_timer = 0;
    static int delayBetweenNotes = 0;

    if (background_tune_notes != 0) 
	{
        if (current_note_timer == 0 && delayBetweenNotes == 0) 
		{
            playNote(background_tune_notes[index]);
            current_note_timer = background_tune_times[index];
            delayBetweenNotes = background_tune_times[index] * 0.2;
            
            // Move to next note
            index++;
            if (index >= background_tune_note_count) 
			{
                if (background_repeat_tune == 0) 
				{
                    background_tune_notes = 0;
                } 
				else {
                    index = 0;
                }
            }
        }
        
        // Handle note duration countdown
        if (current_note_timer > 0) {
            current_note_timer--;
            if (current_note_timer == 0) {
                playNote(0); // Silence between notes
            }
        }
        
        // Handle delay countdown
        if (delayBetweenNotes > 0) {
            delayBetweenNotes--;
        }
    }
}
void initClock(void)
{
// This is potentially a dangerous function as it could
// result in a system with an invalid clock signal - result: a stuck system
        // Set the PLL up
        // First ensure PLL is disabled
        RCC->CR &= ~(1u<<24);
        while( (RCC->CR & (1 <<25))); // wait for PLL ready to be cleared
        
// Warning here: if system clock is greater than 24MHz then wait-state(s) need to be
// inserted into Flash memory interface
				
        FLASH->ACR |= (1 << 0);
        FLASH->ACR &=~((1u << 2) | (1u<<1));
        // Turn on FLASH prefetch buffer
        FLASH->ACR |= (1 << 4);
        // set PLL multiplier to 12 (yielding 48MHz)
        RCC->CFGR &= ~((1u<<21) | (1u<<20) | (1u<<19) | (1u<<18));
        RCC->CFGR |= ((1<<21) | (1<<19) ); 

        // Need to limit ADC clock to below 14MHz so will change ADC prescaler to 4
        RCC->CFGR |= (1<<14);

        // and turn the PLL back on again
        RCC->CR |= (1<<24);        
        // set PLL as system clock source 
        RCC->CFGR |= (1<<1);
}
void delay(volatile uint32_t dly)
{
	uint32_t end_time = dly + milliseconds;
	while(milliseconds != end_time)
		__asm(" wfi "); // sleep
}

void enablePullUp(GPIO_TypeDef *Port, uint32_t BitNumber)
{
	Port->PUPDR = Port->PUPDR &~(3u << BitNumber*2); // clear pull-up resistor bits
	Port->PUPDR = Port->PUPDR | (1u << BitNumber*2); // set pull-up bit
}
void pinMode(GPIO_TypeDef *Port, uint32_t BitNumber, uint32_t Mode)
{
	/*
	*/
	uint32_t mode_value = Port->MODER;
	Mode = Mode << (2 * BitNumber);
	mode_value = mode_value & ~(3u << (BitNumber * 2));
	mode_value = mode_value | Mode;
	Port->MODER = mode_value;
}

			
void setupIO()
{
	RCC->AHBENR |= (1 << 18) + (1 << 17); // enable Ports A and B
	display_begin();
	pinMode(GPIOB,4,0);
	pinMode(GPIOB,5,0);
	pinMode(GPIOA,8,0);
	pinMode(GPIOA,11,0);
	enablePullUp(GPIOB,4);
	enablePullUp(GPIOB,5);
	enablePullUp(GPIOA,11);
	enablePullUp(GPIOA,8);
}

int flip(short num)
{
	if(num==1)
	{
		num = 0;
	}
	else
	{
		num = 1;
	}

	return num;
}


int winCheck()
{
	if(isInside(52, 22, 8,8, charaSprite.x, charaSprite.y) ||
		isInside(52, 22, 8,8, charaSprite.x+CHAR_X, charaSprite.y) ||
		isInside(52, 22, 8,8, charaSprite.x, charaSprite.y+CHAR_Y) ||
		isInside(52, 22, 8,8, charaSprite.x+CHAR_X, charaSprite.y+CHAR_Y))
	{
		return 1;
	}
	return 0;

}

void mainMenuLogic()
{
	innitPrintMenuText();
	playMainMenu(); // menu music

	while (gameStatus.gameStart == 0)
	{
		mainMenu();

		// if anything is confirmed, break out
		if (gameStatus.menuOption == 0 && gameStatus.menuConfirm == 1)
		{
			gameStatus.gameStart = 1;
			break;
		}
		else if (gameStatus.menuOption == 1 && gameStatus.menuConfirm == 1)
		{
			gameStatus.soundtrackStart = 1;
			break;
		}
		delay(200);
		// reset just in case
		gameStatus.menuConfirm = 0;
	}
}
void soundTrackLogic()
{

	gameStatus.menuOption = 0;
	gameStatus.menuConfirm = 0;
	while (gameStatus.soundtrackStart == 1)
	{
		soundMenu();
		printSoundMenu(gameStatus.menuOption);
		delay(200);

		if (gameStatus.menuConfirm == 1)
		{
			selectedSong(gameStatus.menuOption);
		}
		if (gameStatus.menuConfirm == -1)
		{

			// printDecimal(gameStatus.menuConfirm);
			mute();
			gameStatus.soundtrackStart = 0;
		}

		// printDecimal(gameStatus.menuConfirm);
		gameStatus.menuConfirm = 0;
	}
}

void runMainGame()
{
	// startup of game
	gameStatus.gameStart = 0;
	gameStatus.playerWon = 0;
	gameStatus.playerLives = 3;

	// play Song
	playGameMusic();
	while (gameStatus.playerLives >= 0 && gameStatus.playerWon == 0)
	{
		gameStatus.playerHit = 0;
		metalSetup();
		putImage(10, 34,16,16,donkeyKong,0,0);
		barrelInnit();
		charaInnit();

		// main game loop
		while (gameStatus.playerHit == 0 && gameStatus.playerWon == 0)
		{
			charaMovement();
			barrelMovement(1);
			spawnBarrels();

			if (winCheck())
			{
				gameStatus.playerWon = 1;
			}

			delay(50);
		}
		clearBarrels();
		clear();
	}
	// if we broken out of the while means the game is over

	mute();
	if (gameStatus.playerWon == 1)
	{
		playWin();
		printTextX2("You Win!!", 10, 60, 0xFFFF, 0x0000);
		delay(5000);
	}
	else
	{
		playLose();
		printTextX2("You Lose!!", 10, 60, 0xFFFF, 0x0000);
		delay(5000);
	}

	gameStatus.gameStart = 0;
	clear();
}
