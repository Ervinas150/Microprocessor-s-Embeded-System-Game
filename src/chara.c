#include "chara.h"
#include "main.h"
#include "metal.h"
#include "display.h"
#include "serial.h"

void charaInnit()
{

    charaSprite.hinverted  = 0;
    charaSprite.vinverted = 0;
    charaSprite.toggle = 0;
    charaSprite.hmoved = 0;
    charaSprite.vmoved = 0;
    charaSprite.falling = 0;
    charaSprite.hittingWall = 0;
    charaSprite.x = 10;
    charaSprite.y = 140;
    charaSprite.oldx = charaSprite.x;
    charaSprite.oldy = charaSprite.y;
}


void charaMovement() 
{


    // main character movements
    if (isOnPipe(charaSprite.x, charaSprite.y, charaSprite.x + CHAR_X, charaSprite.y + CHAR_Y))
    {
        charaSprite.falling = 0;
    }
    else
    {
        charaSprite.falling = 1;
        charaSprite.y++;
        // fillRectangle(oldx,oldy,6,10,0);
        // putImage(x,y,6,10,main_chara,hinverted,0);
    }
    // simply check if we are hitting the wall before checking movements
    charaSprite.hittingWall = isHittingWall(charaSprite.x, charaSprite.y);

    charaSprite.hmoved = charaSprite.vmoved = 0;
    charaSprite.hinverted = charaSprite.vinverted = 0;

    if ((GPIOB->IDR & (1 << 4)) == 0) // right pressed & not hitting wall
    {
        if (charaSprite.x < SCREEN_WIDTH - CHAR_X && charaSprite.hittingWall != 1)
        {
            printDecimal(charaSprite.hittingWall);
            charaSprite.x = charaSprite.x + 2;
            charaSprite.hmoved = 1;
            charaSprite.hinverted = 0;
        }
    }
    if ((GPIOB->IDR & (1 << 5)) == 0) // left pressed
    {

        if (charaSprite.x > 1 && charaSprite.hittingWall != 2)
        {
            printDecimal(charaSprite.hittingWall);
            charaSprite.x = charaSprite.x - 2;
            charaSprite.hmoved = 1;
            charaSprite.hinverted = 1;
        }
    }

    static short jumpWasPressed = 0;
    if ((GPIOA->IDR & (1 << 8)) == 0) // up pressed  & not about to hit head
    {
        //tracks if we are holding jump


        int jumpWait = 500;
        static uint32_t lastJump = 0;

        if( (!jumpWasPressed) && (charaSprite.y > 5) && (charaSprite.hittingWall != 3) &&
            (milliseconds - lastJump > jumpWait) && (charaSprite.falling == 0) )
        {
            printDecimal(charaSprite.hittingWall);
            charaSprite.y = charaSprite.y - 5;
            charaSprite.vmoved = 1;
            charaSprite.vinverted = 0;

            lastJump = milliseconds;
            jumpWasPressed = 1;


        }

        else if(jumpWasPressed && (charaSprite.y > 5) && (charaSprite.hittingWall != 3) )
        {
            printDecimal(charaSprite.hittingWall);
            charaSprite.y = charaSprite.y - 4;
            charaSprite.vmoved = 1;
            charaSprite.vinverted = 0;

            lastJump = milliseconds;
        }


    }
    else
    {
        jumpWasPressed = 0;

    }

    if ((charaSprite.vmoved) || (charaSprite.hmoved) || (charaSprite.falling))
    {
        // only redraw if there has been some movement (reduces flicker)
        fillRectangle(charaSprite.oldx, charaSprite.oldy, 6, 10, 0);
        charaSprite.oldx = charaSprite.x;
        charaSprite.oldy = charaSprite.y;
        if (charaSprite.hmoved)
        {
            if (charaSprite.toggle)
                putImage(charaSprite.x, charaSprite.y, 6, 10, main_chara, charaSprite.hinverted, 0);
            else
                putImage(charaSprite.x, charaSprite.y, 6, 10, main_chara, charaSprite.hinverted, 0);

            charaSprite.toggle = charaSprite.toggle ^ 1;
        }
        else
        {
            putImage(charaSprite.x, charaSprite.y, 6, 10, main_charaJump, 0, charaSprite.vinverted);
        }
    }
}
