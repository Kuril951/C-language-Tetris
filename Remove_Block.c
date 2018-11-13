#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"gotoxy.h"
#include"Block.h"

void Remove_Block(int Choice,int Dot_x,int Dot_y)
{
	int x,y;
	for(y=0; y<4; y++)
	{
		for(x=0; x<4; x++)
		{
			gotoxy(Dot_x+2*x,Dot_y+y);
			if(Block[Choice][y][x] == 1)
				printf("  ");
		}
	}
}