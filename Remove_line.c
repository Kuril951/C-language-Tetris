#include"gotoxy.h"
#include<stdio.h>
#include<Windows.h>

extern int Stack[21][13];

void Score_Show(int);												//���� �����ֱ�

void Remove_line()
{
	int i,k;
	int count=0;
	int line=0;

	for(i=1; i<20; i++)
	{
		for(k=1; k<12; k++)
		{
			if(Stack[i][k] == 1)
				count++;
		}//for
		if(count==11)							//���� �������� �� �����
		{
			for(; i>0; i--)
			{
				for(k=1; k<12; k++)
				{
					Stack[i][k]=0;
					gotoxy(2*k+10,2+i);
					printf("  ");
					Stack[i][k] = Stack[i-1][k];

					if(Stack[i][k] == 1)
					{
						gotoxy(10+2*k,2+i);
						printf("��");
					}//if
				}//for
			}//for
			line++;					//���� ���ΰ���
		}//if
		count=0;
	}//for
	Score_Show(line);
}//Remove_line