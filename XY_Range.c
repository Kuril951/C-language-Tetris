#include"Block.h"
#include"Definition.h"

extern int Stack[21][13];

int XY_Range(int Choice,int x,int y)			//�ٲ����� ��ǥx,y
{
	int a=0,b=0;
	int i=1;

	for(a=0; a<4; a++)
	{
		for(b=0; b<4; b++)
		{
			if(Block[Choice][a][b] == 1)									//������ �����
			{
				//if((x+(2*b)) == 10 || (x+(2*b)) == Width+10)
				if(Stack[y+a-2][(x-10)/2+b]==1)
					return 0;
				if(Stack[y+a-2][(x-10)/2+b]==1 )//Stack[y+a-2][(x-10)/2+b]==1)
					return 0;		//�浹
			}//if
		}
	}
	return 1;
}