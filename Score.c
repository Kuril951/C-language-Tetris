#include<stdio.h>
#include"gotoxy.h"

void Score_Show(int line)
{
	static int Score=0;

	switch(line)
	{
	case 0:
		Score+=0;
		break;
	case 1:
		Score+=100;
		break;
	case 2:
		Score+=300;
		break;
	case 3: 
		Score+=600;
		break;
	case 4:
		Score+=1000;
		break;
	}
	
	gotoxy(54,2);
	printf("SCORE : %10d",Score);
}