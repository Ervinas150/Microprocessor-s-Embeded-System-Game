#include "menu.h"
#include "main.h"
#include "display.h"
#include "sound.h"
#include "musical_notes.h"


//MAIN MENU
void innitPrintMenuText()
{
    gameStatus.menuOption = 0;
    gameStatus.menuConfirm = 0;
    printText("Welcome to...", 20,20,RGBToWord(255,255,255),RGBToWord(0,0,0));
    delay(1000);
    printText("Donkey", 60,35,RGBToWord(255,0,0),RGBToWord(0,0,0));
    delay(800);
    printTextX2("KONG.", 70,50,RGBToWord(255,0,0),RGBToWord(0,0,0));

    printText("Start Game",20, 100, RGBToWord(255,100,0), RGBToWord(0,0,0));
    printText("Soundtrack", 20, 110,RGBToWord(255,255,255), RGBToWord(0,0,0));
    printText(">", 10, 100, RGBToWord(255,100,0), RGBToWord(0,0,0));
    
}

//to be run in a while loop
void mainMenu()
{
    // navigation
    if ((GPIOB->IDR & (1 << 5)) == 0) // left pressed
    {
        gameStatus.menuConfirm = -1;
    }
    if ((GPIOB->IDR & (1 << 4)) == 0) // right pressed
    {
        gameStatus.menuConfirm = 1;
    }
    if ((GPIOA->IDR & (1 << 11)) == 0) // down pressed
    {
        gameStatus.menuOption = 1;
    }
    if ((GPIOA->IDR & (1 << 8)) == 0) // up pressed
    {
        gameStatus.menuOption = 0;
    }

    if (gameStatus.menuOption == 0)
    {
        fillRectangle(10,110,10,10,RGBToWord(0,0,0));
        printText("Start Game", 20, 100, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
        printText("Soundtrack", 20, 110, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
        printText(">", 10, 100, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
    }
    else
    {
        fillRectangle(10,100,10,10,RGBToWord(0,0,0));
        printText("Start Game", 20, 100, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
        printText("Soundtrack", 20, 110, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
        printText(">", 10, 110, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
    }

}



//SOUND MENU
void printSoundMenu(int x) 
{
    switch (x)
    {
        case 0:
        {
            fillRectangle(10,20,10,60,RGBToWord(0,0,0));
            printText(">", 10, 20, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
            printText("Main Theme", 20, 20, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
            printText("In game", 20, 30, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Winner!", 20, 40, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Loser! :C", 20, 50, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Secret sound", 20, 60, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));

            break;
        }
        case 1:
        {
            fillRectangle(10,20,10,60,RGBToWord(0,0,0));
            printText(">", 10, 30, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
            printText("Main Theme", 20, 20, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("In game", 20, 30, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
            printText("Winner!", 20, 40, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Loser! :C", 20, 50, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Secret sound", 20, 60, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));

            break;
        }
        case 2:
        {
            fillRectangle(10,20,10,60,RGBToWord(0,0,0));
            printText(">", 10, 40, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
            printText("Main Theme", 20, 20, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("In game", 20, 30, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Winner!", 20, 40, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
            printText("Loser! :C", 20, 50, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Secret sound", 20, 60, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));

            break;
        }
        case 3:
        {
            fillRectangle(10,20,10,60,RGBToWord(0,0,0));
            printText(">", 10, 50, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
            printText("Main Theme", 20, 20, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("In game", 20, 30, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Winner!", 20, 40, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Loser! :C", 20, 50, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
            printText("Secret sound", 20, 60, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));

            break;
        }
        case 4:
        {
            fillRectangle(10,20,10,60,RGBToWord(0,0,0));
            printText(">", 10, 60, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
            printText("Main Theme", 20, 20, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("In game", 20, 30, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Winner!", 20, 40, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Loser! :C", 20, 50, RGBToWord(255, 255, 255), RGBToWord(0, 0, 0));
            printText("Secret sound", 20, 60, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));

            break;
        }

        default:
        {
            clear();
            printText("ERROR", 20, 60, RGBToWord(255, 100, 0), RGBToWord(0, 0, 0));
            break;
        }
    }
    
    // maybe add a music note image to make it look nicer?

}

void soundMenu()
{
    gameStatus.menuConfirm = 0;
    // navigation
    if ((GPIOB->IDR & (1 << 5)) == 0) // left pressed
    {
        gameStatus.menuConfirm -=1;
        gameStatus.menuConfirm = gameStatus.menuConfirm % 2;
    }
    if ((GPIOB->IDR & (1 << 4)) == 0) // right pressed
    {
        gameStatus.menuConfirm += 1;
        gameStatus.menuConfirm = gameStatus.menuConfirm % 2;
        printDecimal(gameStatus.menuConfirm);
    }
    if ((GPIOA->IDR & (1 << 11)) == 0) // down pressed
    {
        gameStatus.menuOption +=1;
        gameStatus.menuOption = gameStatus.menuOption % 5;
    }
    if ((GPIOA->IDR & (1 << 8)) == 0) // up pressed
    {
        gameStatus.menuOption -=1;
        gameStatus.menuOption = (gameStatus.menuOption+5) % 5 ;// +5 to prevent negative numbers 
    }

    
}

void selectedSong()
{
	printDecimal(gameStatus.menuConfirm);
    switch (gameStatus.menuOption)
    {
    case 0:
    {
		printDecimal(2222);
        playMainMenu();
        break;
    }
    case 1:
    {
        playGameMusic();
        break;
    }
    case 2:
    {
        playWin();
        break;
    }
    case 3:
    {
        playLose();
        break;
    }
    case 4:
    {
        playSecretSong();
        break;
    }

    default:
        mute();
        break;
    }
}


void playSecretSong()
{
    //static so it initialises only once
    static const uint32_t melody[] = { 
        D4, D4, D5, 0, A4, 0, GS4_Ab4, 0, 
        G4, 0, F4, 0, D4, F4, G4,
        C4, C4, D5, 0, A4, 0, GS4_Ab4, 0,
        G4, 0, F4, 0, D4, F4, G4
    };
    
    static const uint32_t durations[] = { 
        200, 200, 400, 100, 300, 100, 300, 100,
        300, 100, 300, 100, 200, 200, 200,
        200, 200, 400, 100, 300, 100, 300, 100,
        300, 100, 300, 100, 200, 200, 200
    };

    uint16_t noteCount = sizeof(melody) / 4;
    background_tune_notes = melody;
    background_tune_times = durations;
    background_tune_note_count = noteCount;
    background_repeat_tune = 1;

}
    