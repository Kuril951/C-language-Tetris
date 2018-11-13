#include"Block.h"

extern int Stack[21][13];					//블럭 쌓이는 것 저장

void Stack_Check(int Choice,int x,int y)			//블럭 좌표
{
	int a=0,b=0;										//x-b ,y-a

	for(a=0; a<4; a++)
	{
		for(b=0; b<4; b++)
		{
			if(Block[Choice][a][b] == 1)
			{
				Stack[y-2+a][(x-10)/2+b] = 1;			//좌표 저장
			}//if
		}//for
	}//for
}//Stack_Check