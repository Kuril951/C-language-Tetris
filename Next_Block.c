#include<stdio.h>
#include"gotoxy.h"
#include"Block.h"

void Next_Block(int Next_Choice)
{
	int x,y;
	int a;

	gotoxy(40,2);
	printf("�������");
	for(a=0; a<4; a++)
	{
		gotoxy(40,3+a);
		printf("��        ��");
	}
	gotoxy(40,7);
	printf("�������");

	for(y=0; y<4; y++)
	{
		for(x=0; x<4; x++)
		{
			gotoxy(2*x+42,y+3);
			if(Block[Next_Choice][y][x] == 1)
				printf("��");
		}
	}//for
}