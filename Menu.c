#include<stdio.h>
#include"gotoxy.h"
#include"Definition.h"

void Menu()
{
	int i;
	gotoxy(10,2);
	printf("��������������������������������������������������\n");
	for(i=0; i<Height; i++)
	{
		gotoxy(10,3+i);
		printf("��");
		gotoxy(10+Width,3+i);
		printf("��");
	}
	gotoxy(10,22);
	printf("��������������������������������������������������\n");

}