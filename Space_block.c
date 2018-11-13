#include"Block.h"
#include"gotoxy.h"
extern int Stack[21][13];

int XY_Range(int Choice,int x,int y);				//범위확인
void Create_Block(int Choice,int Dot_x,int Dot_y);
void Stack_Check(int Choice,int x,int y);

void Space_block(int Choice,int Dot_x,int Dot_y)
 {
	 int a,b;

	 for(a=0; a<21; a++)
	{
		if(XY_Range(Choice,Dot_x,Dot_y) == 1)
			Dot_y++;
		else 
		{
			Dot_y--;
			gotoxy(Dot_x,Dot_y);
			Create_Block(Choice,Dot_x,Dot_y);
			Stack_Check(Choice,Dot_x,Dot_y);
			break;
		}

	}//for
 }