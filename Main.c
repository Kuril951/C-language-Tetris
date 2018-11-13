#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include"Block.h"						//��� �������
#include"Definition.h"
#include"gotoxy.h"		//����

void removeCursor();
void Menu();
void Create_Block(int,int,int);									//��� ���� (������)
void Remove_Block(int,int,int);									//��� ����	(������)
int XY_Range(int,int,int);
void Stack_Check(int,int,int);
void Remove_line();												//���ٿϼ������� ������
void Space_block(int,int,int);									//�����̽��� ��������
int End_Game(int Choice);										//��������Ȯ��
void Next_Block(int Next_Choice);								//���� �� �����ֱ�
void Score_Show(int);											//���� �����ֱ�

struct Block_xy
{
	int x,y;
};

int Stack[21][13]={{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,0,0,0,0,0,0,0,0,0,0,0,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main()
{
	struct Block_xy Dot;
	int GameOver = FALSE;
	int ch;
	int Block_Crash = TRUE;					//�浹 Ȯ��
	int Choice;								//�� ���
	int Down_count=0;						//�� �ϰ��ӵ� ����
	int Change_temp;						//��� ���� �ӽ� ����
	int Next_Choice;						//���� ��
	int first_line=0;						//�ʱ⿡ ������ ����

	srand((unsigned)time(NULL));
	Menu();									//�޴������
	removeCursor();							//Ŀ�������
	Score_Show(first_line);					//��������

	Next_Choice = (rand()%7)*4;				//�����ϱ����� �����ֱ�

	while(GameOver == FALSE)
	{
		fflush(stdin);
		if(Block_Crash == TRUE)
		{
			Choice=Change_temp=Next_Choice;				//�����
			Next_Choice = (rand()%7)*4;					//������
			Next_Block(Next_Choice);
			if(End_Game(Choice) == 0)
			{
				gotoxy(40,10);
				printf("GAME OVER.\n");
				gotoxy(40,11);
				break;
			}
			Dot.x=20;
			Dot.y=3;
			Create_Block(Choice,Dot.x,Dot.y);
			Block_Crash = FALSE;
		}

		if(kbhit())
		{
			ch = getch();
			switch(ch)
			{
			case UP:				//�������ٲٱ�
				Remove_Block(Choice,Dot.x,Dot.y);
				if(Change_temp+3<++Choice)
					Choice = Change_temp;
				if(XY_Range(Choice,Dot.x,Dot.y) == 0)
					Choice = Choice--;
				Create_Block(Choice,Dot.x,Dot.y);
				break;
			case DOWN:				//�������� �ӵ�����
				Down_count+=10;
				continue;
				break;
			case RIGHT:				//��� x++
				Remove_Block(Choice,Dot.x,Dot.y);
				Dot.x+=2;
				if(XY_Range(Choice,Dot.x,Dot.y) == 0)
					Dot.x-=2;
				Create_Block(Choice,Dot.x,Dot.y);
				break;
			case LEFT:				//��� x--
				Remove_Block(Choice,Dot.x,Dot.y);
				Dot.x-=2;
				if(XY_Range(Choice,Dot.x,Dot.y) == 0)
					Dot.x+=2;
				Create_Block(Choice,Dot.x,Dot.y);
				break;
			case SPACE:				//�����̽��� ��� �ѹ��� ����
				Remove_Block(Choice,Dot.x,Dot.y);
				Space_block(Choice,Dot.x,Dot.y);
				Block_Crash = TRUE;
				Down_count=0;
				Remove_line();
				break;
			default:;//�߸����°� ����
			}
		}//if

		if(Down_count >= 50)
		{
			if(XY_Range(Choice,Dot.x,++Dot.y) == 0)
			{
				Block_Crash = TRUE;						//�ٴڿ� ����.
				Dot.y--;
				Stack_Check(Choice,Dot.x,Dot.y);
				Remove_line();
			}//if
			else
			{
				Remove_Block(Choice,Dot.x,--Dot.y);
				Dot.y+=1;								//��ĭ ��������
				Create_Block(Choice,Dot.x,Dot.y);
			}

			Down_count=0;							//�ٽ� �ʱ�ȭ
		}

		Down_count++;								//�������� �ӵ� ����
		Sleep(1000/100);
	}

	getch();
	return 0;
}