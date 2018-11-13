#include<stdio.h>
#include"gotoxy.h"
#include"Definition.h"

void Menu()
{
	int i;
	gotoxy(10,2);
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	for(i=0; i<Height; i++)
	{
		gotoxy(10,3+i);
		printf("弛");
		gotoxy(10+Width,3+i);
		printf("弛");
	}
	gotoxy(10,22);
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式戎\n");

}