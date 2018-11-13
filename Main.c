#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include"Block.h"						//블록 모양저장
#include"Definition.h"
#include"gotoxy.h"		//삭제

void removeCursor();
void Menu();
void Create_Block(int,int,int);									//블록 생성 (움직임)
void Remove_Block(int,int,int);									//블록 제거	(움직임)
int XY_Range(int,int,int);
void Stack_Check(int,int,int);
void Remove_line();												//한줄완성됬을지 줄지움
void Space_block(int,int,int);									//스페이스바 눌렀을때
int End_Game(int Choice);										//게임종료확인
void Next_Block(int Next_Choice);								//다음 블럭 보여주기
void Score_Show(int);											//점수 보여주기

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
	int Block_Crash = TRUE;					//충돌 확인
	int Choice;								//블럭 모양
	int Down_count=0;						//블럭 하강속도 조절
	int Change_temp;						//모양 변경 임시 변수
	int Next_Choice;						//다음 블럭
	int first_line=0;						//초기에 터지는 라인

	srand((unsigned)time(NULL));
	Menu();									//메뉴만들기
	removeCursor();							//커서지우기
	Score_Show(first_line);					//점수보기

	Next_Choice = (rand()%7)*4;				//시작하기전에 정해주기

	while(GameOver == FALSE)
	{
		fflush(stdin);
		if(Block_Crash == TRUE)
		{
			Choice=Change_temp=Next_Choice;				//현재것
			Next_Choice = (rand()%7)*4;					//다음것
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
			case UP:				//도형모양바꾸기
				Remove_Block(Choice,Dot.x,Dot.y);
				if(Change_temp+3<++Choice)
					Choice = Change_temp;
				if(XY_Range(Choice,Dot.x,Dot.y) == 0)
					Choice = Choice--;
				Create_Block(Choice,Dot.x,Dot.y);
				break;
			case DOWN:				//내려오는 속도증가
				Down_count+=10;
				continue;
				break;
			case RIGHT:				//블록 x++
				Remove_Block(Choice,Dot.x,Dot.y);
				Dot.x+=2;
				if(XY_Range(Choice,Dot.x,Dot.y) == 0)
					Dot.x-=2;
				Create_Block(Choice,Dot.x,Dot.y);
				break;
			case LEFT:				//블록 x--
				Remove_Block(Choice,Dot.x,Dot.y);
				Dot.x-=2;
				if(XY_Range(Choice,Dot.x,Dot.y) == 0)
					Dot.x+=2;
				Create_Block(Choice,Dot.x,Dot.y);
				break;
			case SPACE:				//스페이스바 블록 한번에 내림
				Remove_Block(Choice,Dot.x,Dot.y);
				Space_block(Choice,Dot.x,Dot.y);
				Block_Crash = TRUE;
				Down_count=0;
				Remove_line();
				break;
			default:;//잘못들어온값 무시
			}
		}//if

		if(Down_count >= 50)
		{
			if(XY_Range(Choice,Dot.x,++Dot.y) == 0)
			{
				Block_Crash = TRUE;						//바닥에 닿음.
				Dot.y--;
				Stack_Check(Choice,Dot.x,Dot.y);
				Remove_line();
			}//if
			else
			{
				Remove_Block(Choice,Dot.x,--Dot.y);
				Dot.y+=1;								//한칸 내려오기
				Create_Block(Choice,Dot.x,Dot.y);
			}

			Down_count=0;							//다시 초기화
		}

		Down_count++;								//내려오는 속도 조절
		Sleep(1000/100);
	}

	getch();
	return 0;
}