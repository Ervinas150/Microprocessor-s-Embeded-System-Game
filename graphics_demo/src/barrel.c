#include "main.h"
#include "metal.h"
#include "barrel.h"
#include "display.h"
#include "serial.h"
#include "chara.h"

void barrelInnit()
{
	uint16_t barrelDelay = 1250;
	uint32_t lastBarrelThrown = milliseconds;
	int barrelPresent = 0;
	

	//start sequence of the game, idea is to spawn 7 and only then the player can move
	while(1)
	{
		if(milliseconds - lastBarrelThrown > barrelDelay)
		{
			createBarrels(barrelPresent);
			lastBarrelThrown = milliseconds;

			barrelPresent++;
			if(barrelPresent == 7)
			{
				break;
			}
		}
		//move faster to decrease wait time
		barrelMovement(2);

		delay(50);

	}
}

//main movement of the barrels
void barrelMovement(int speedBarrel)
{
	int i;

	//for every barrel
	for (i = 0; i < BARRELLIMIT; i++)
	{
		//if barrel isnt made yet, skip to next iteration
		if(!barrelSprite[i].created)
		{
			continue;
		}

		barrelSprite[i].barrelMoved = 0;

		//find out if we are falling
		barrelSprite[i].barrelFalling = isOnPipe(barrelSprite[i].x, barrelSprite[i].y, barrelSprite[i].x + XBARREL, barrelSprite[i].y + YBARREL);

		// if the barrell is ON a pipe and on screen, move x
		if (barrelSprite[i].x < SCREEN_WIDTH - 5 && barrelSprite[i].barrelFalling == 1)
		{
			// check to see if we are going left or right
			if (barrelSprite[i].RLount == 1) //left
			{
				barrelSprite[i].x = barrelSprite[i].x - speedBarrel;
			}
			else //right
			{
				barrelSprite[i].x = barrelSprite[i].x + speedBarrel;
			}
			barrelSprite[i].barrelMoved = 1;
		}

		if (barrelSprite[i].y < SCREEN_HEIGHT - 5 && barrelSprite[i].barrelFalling == 0)
		{
			barrelSprite[i].y = barrelSprite[i].y + speedBarrel;
			barrelSprite[i].barrelMoved = 1;
		}
		
		// if we hit either end, flip the side we go to
		if (barrelSprite[i].x < 5 || barrelSprite[i].x >= SCREEN_WIDTH - 10)
		{
			barrelSprite[i].RLount = flip(barrelSprite[i].RLount);
		}

		//making the moves we did visible and look good
		if (barrelSprite[i].barrelMoved == 1)
		{
			fillRectangle(barrelSprite[i].oldx, barrelSprite[i].oldy, 5, 5, 0);

			barrelSprite[i].oldx = barrelSprite[i].x;
			barrelSprite[i].oldy = barrelSprite[i].y;
			putImage(barrelSprite[i].x, barrelSprite[i].y, 5, 5, barrel, 0, 0);
		}
		if (isInside(barrelSprite[i].x, barrelSprite[i].y, 5, 5, charaSprite.x, charaSprite.y) 
		|| isInside(barrelSprite[i].x, barrelSprite[i].y, 5, 5, charaSprite.x+CHAR_X, charaSprite.y)
		|| isInside(barrelSprite[i].x, barrelSprite[i].y, 5, 5, charaSprite.x, charaSprite.y+CHAR_Y) 
		|| isInside(barrelSprite[i].x, barrelSprite[i].y, 5, 5, charaSprite.x+CHAR_X, charaSprite.y+CHAR_Y))
		{
			gameStatus.playerHit = 1;
			gameStatus.playerLives -=1;
			barrelSprite[i].created = 0;

		}
	}
	
	didReachedEnd();

}

void createBarrels(int i)
{
	barrelSprite[i].created = 1;
	barrelSprite[i].x = 30;
	barrelSprite[i].y = 10;
	barrelSprite[i].oldx = barrelSprite[i].x;
	barrelSprite[i].oldy = barrelSprite[i].y;
	barrelSprite[i].RLount = 0;
}


void didReachedEnd() 
{
	for(int i = 0; i < BARRELLIMIT; i++)
	{
		if(barrelSprite[i].y > 140 && barrelSprite[i].x < 20)
		{
			barrelSprite[i].created = 0;
			fillRectangle(barrelSprite[i].x, barrelSprite[i].y, 5, 5, 0);
			

		}

	}

}

void spawnBarrels()
{
	uint16_t barrelDelay = 3500;
	static uint32_t lastBarrelThrown = 0;
	int i;

	//check for barrels
	for(i = 0; i < BARRELLIMIT; i++)
	{
		if(barrelSprite[i].created == 0 && milliseconds - lastBarrelThrown > barrelDelay)
		{	
			createBarrels(i);
			lastBarrelThrown = milliseconds;

		}
	}


}

void clearBarrels()
{
	for(int i = 0; i < BARRELLIMIT; i++)
	{
		barrelSprite[i].created = 0;
		barrelSprite[i].x = 0;
		barrelSprite[i].y = 0;
		barrelSprite[i].oldx = barrelSprite[i].x;
		barrelSprite[i].oldy = barrelSprite[i].y;
		barrelSprite[i].RLount = 0;
		short barrelMoved = 0;
		short barrelFalling = 0;
	}
}
