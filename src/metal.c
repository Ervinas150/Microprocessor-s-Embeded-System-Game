#include "display.h"
#include "main.h"
#include "metal.h"
#include "chara.h"

void metalSetup()
{
	//bottom layer
	putImage(0,155, 20, 3, metal,0,0);
	putImage(20,155, 20, 3, metal,0,0);
	putImage(40,150, 20, 3, metal,0,0);
	putImage(60,150, 20, 3, metal,0,0);
	putImage(80,150, 20, 3, metal,0,0);
	putImage(100,145, 20, 3, metal,0,0);

	//second layer
	putImage(80,120, 20, 3, metal,0,0);
	putImage(60,120, 20, 3, metal,0,0);
	putImage(40,115, 20, 3, metal,0,0);
	putImage(20,115, 20, 3, metal,0,0);
	putImage(0,110, 20, 3, metal,0,0);

	//third layer
	putImage(20,85, 20, 3, metal,0,0);
	putImage(40,85, 20, 3, metal,0,0);
	putImage(60, 80,20, 3, metal,0,0);
	putImage(80,80, 20, 3, metal,0,0);
	putImage(100, 75, 20, 3, metal,0,0);

	//final layer
	putImage(80, 50, 20, 3, metal,0,0);
	putImage(60, 50, 20, 3, metal,0,0);
	putImage(40, 50, 20, 3, metal,0,0);
	putImage(20, 50, 20, 3, metal,0,0);
	putImage(0, 50, 20, 3, metal,0,0);

	//trophy
	putImage(40, 30, 20, 3, metal, 0,0);
	putImage(52, 22, 8, 8, trophy, 0,0);

}


//if (isInside(20,80,6,10,x,y) || isInside(20,80,6,10,x+6,y) || isInside(20,80,12,16,x,y+10) || isInside(20,80,6,10,x+6,y+10) )

int isInside(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint16_t px, uint16_t py)
{
	// checks to see if point px,py is within the rectange defined by x,y,w,h
	uint16_t x2,y2;
	x2 = x1+w;
	y2 = y1+h;
	int rvalue = 0;
	if ( (px >= x1) && (px <= x2))
	{
		// ok, x constraint met
		if ( (py >= y1) && (py <= y2))
			rvalue = 1;
	}
	return rvalue;
}

int isClose(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint16_t px, uint16_t py)
{
	// checks to see if point px,py is close to a 4 point shape
	short int pixelGap = 2;
	uint16_t x2,y2;
	x2 = x1+w;
	y2 = y1+h;
	int rvalue = 0;
	if ( (px >= x1-pixelGap && px <= x1) || (px >= x2+pixelGap && px <= x2))
	{
		// ok, x constraint met
		if ( (py >= y1-pixelGap && py <= y1) || (py >= y2-pixelGap && py <= y2)) 
		{
			rvalue = 1;
		}
	}
	return rvalue;
}

int isCloseMain(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint16_t px, uint16_t py)
{
	// checks to see if point px,py is close to a 4 point shape
	short int pixelGap = 2;
	uint16_t x2,y2,px2,py2;
	px2 = px + CHAR_X;
    py2 = py + CHAR_Y;
	x2 = x1+w;
	y2 = y1+h;

	//we check if we are close to the left wall
	if(px2 >= x1-pixelGap && px2 <= x1)
	{
		// ok, x constraint met
		if(py >= y1 && py <= y2) 
		{
			return 1;
		}

	}//end if
    //check if we are about to hit the right wall
    if( px <= x2+pixelGap && px >= x2)
    {
		// ok, x constraint met
		if(py2 >= y1 && py <= y2) 
		{
			return 2;
		}

    }//end if
	//elseif check if we about to bum our head
	if(py <= y2+pixelGap+2 && py >= y2)
	{
		if(px2 >= x1 && px <= x2)
		{
			return 3;
		}

	}
	//if all ifs fail, we are not close

	return 0;
	

}


int isOnPipe(int xchar, int ychar, int x2char, int y2char) {

	if( isInside(0,50,100,3,xchar,y2char) || isInside(0,50,100,3,x2char,y2char)  //top layer ,we check the left and right side of char
		|| isInsideLayer1(xchar,y2char) || isInsideLayer1(x2char,y2char) //bottom layer
		|| isInsideLayer2(xchar,y2char) || isInsideLayer2(x2char,y2char) //2nd layer
		|| isInsideLayer3(xchar,y2char) || isInsideLayer3(x2char, y2char) //3rd layer
        || isInside(40,30,20,3,xchar,y2char) || isInside(40,30,20,3,x2char,y2char) 
	  )
	{
		return 1;
	}
	else
	{ 
		return 0;

	}
}


int isOnMetalCords(int xchar, int ychar)
{
	if( (isInside(0,50,100,3,xchar,ychar) || isInsideLayer1(xchar, ychar) || isInside(0,50,100,3,xchar,ychar) ) ) 
	{
		return 1;

	}
	else
	{
		return 0;
	}
}


int isInsideLayer1(int xchar, int ychar)
{
	if(isInside(0,155,40,3,xchar,ychar) || isInside(40,150,60,3,xchar, ychar) || isInside(100,145,20,3,xchar, ychar) )
	{
		return 1;
	}
	else
	{
		return 0;
	}


}


int isInsideLayer2(int xchar, int ychar)
{
	if(isInside(60,120,40,3,xchar,ychar) || isInside(20,115,40,3,xchar, ychar) || isInside(0,110,20,3,xchar, ychar))
	{
		return 1;
	}
	else
	{
		return 0;
	}


}


int isInsideLayer3(int xchar, int ychar)
{
	if(isInside(20,85,40,3,xchar,ychar) || isInside(60,80,40,3,xchar, ychar) || isInside(100,75,20,3,xchar, ychar))
	{
		return 1;
	}
	else
	{
		return 0;
	}


}

/*
int isHittingWall(int xchar, int ychar) 
{
	if(isClose(0,50,80,3,xchar,ychar) || isClose(0,50,80,3,xchar,ychar+CHAR_Y) || isClose(0,50,80,3,xchar+CHAR_X,ychar) || isClose(0,50,80,3,xchar+CHAR_X,ychar+CHAR_Y))
	{
		return 1;

	}

}
*/
/*  
	if( isInside(0,50,100,3,xchar,ychar+CHAR_Y) || isInside(0,50,100,3,xchar+CHAR_X,ychar+CHAR_Y)  //top layer ,we check the left and right side of char
		|| isInsideLayer1(xchar,ychar+CHAR_Y) || isInsideLayer1(xchar+CHAR_X,ychar+CHAR_Y) //bottom layer
		|| isInsideLayer2(xchar,ychar+CHAR_Y) || isInsideLayer2(xchar+CHAR_X, ychar+CHAR_Y) //2nd layer
		|| isInsideLayer3(xchar,ychar+CHAR_Y) || isInsideLayer3(xchar+CHAR_X, ychar+CHAR_Y) //3rd layer
        || isInside(40,30,20,3,xchar,ychar+CHAR_Y) || isInside(40,30,20,3,xchar+CHAR_X,ychar+CHAR_X) 
*/
int isHittingWall(int xchar, int ychar)
{
    short sideHit = 0; //0 = none, 1 = left wall, 2 = right wall, 3 = bottom wall

    if( (sideHit = isCloseMain(0,50,100,3,xchar,ychar) ) != 0) //top layer
    {
        return sideHit;
    }
    if((sideHit = isCloseLayer1(xchar,ychar) ) != 0) //bottom layer
    {
        return sideHit;
    }
    if((sideHit = isCloseLayer2(xchar,ychar) ) != 0) //2nd layer
    {
        return sideHit;
    }
    if((sideHit = isCloseLayer3(xchar,ychar) ) != 0) //3rd layer
    {
        return sideHit;
    }
    if((sideHit = isCloseMain(40,30,20,3,xchar,ychar) ) != 0) //winning layer?
    {
        return sideHit;
    }

    return 0;
}

int isCloseLayer1(int xchar, int ychar)
{
    short int wallHit = 0;

	if( (wallHit = isCloseMain(0,155,40,3,xchar,ychar)) != 0 || 
    (wallHit = isCloseMain(40,150,60,3,xchar, ychar)) != 0 || 
    (wallHit = isCloseMain(100,145,20,3,xchar, ychar)) != 0 ) 
	{
		return wallHit;
	}
	else
	{
		return 0;
	}


}

int isCloseLayer2(int xchar, int ychar)
{
    short int wallHit = 0;

	if( (wallHit = isCloseMain(60,120,40,3,xchar,ychar)) != 0 ||
    (wallHit = isCloseMain(20,115,40,3,xchar, ychar)) !=0 ||
    (wallHit = isCloseMain(0,110,20,3,xchar, ychar)) !=0 )
	{
		return wallHit;
	}
	else
	{
		return 0;
	}


}


int isCloseLayer3(int xchar, int ychar)
{
    short int wallHit = 0;
	if( (wallHit = isCloseMain(20,85,40,3,xchar,ychar)) != 0 || 
    (wallHit = isCloseMain(60,80,40,3,xchar, ychar))!= 0 || 
    (wallHit = isCloseMain(100,75,20,3,xchar, ychar)) != 0 )
	{
		return wallHit;
	}
	else
	{
		return 0;
	}


}
