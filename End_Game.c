#include"Block.h"

extern int Stack[21][13];

int End_Game(int Choice)
{
	int i,k;

	for(i=0; i<4; i++)
	{
		for(k=0; k<4; k++)
		{
			if(Block[Choice][i][k] == 1 && Stack[i+1][k+5]==1)
				return 0;
		}
	}//for	
	return 1;
}//End_Game