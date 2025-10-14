#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


int main(void)
{
int x, y;
int xx = 5, yy = 5;
char map[11][21];

char action;

do
{
	system("cls");
if     (action == 'w' && map[xx - 1][yy] != '#') xx--;
else if(action == 's'&& map[xx + 1][yy] != '#') xx++;
else if(action == 'a'&& map[xx][yy - 1] != '#') yy--;
else if(action == 'd'&& map[xx][yy + 1] != '#') yy++;

	for(x = 0; x <= 10; x++)
	{
		for(y = 0; y <= 20; y++)
		{
			if(x == xx && y == yy)
			{
				printf("*");
			}
		 	else if(x == 0 || x == 10)
		 	{
		 		printf("#");	
		 		map[x][y] = '#';
 		 		if(y == 20)
		 		{
		 			printf("\n");
		 		}
		 	}
		 	else if(y == 0)	
		 	{
		 		printf("#");
		 		map[x][y] = '#';
		 	}
		 	else if(y == 20)
		 	{
		 		printf("#\n");
		 		map[x][y] = '#';
		 	}
		 	else
		 	{
		 		printf(" ");
		 		map[x][y] = ' ';
		 	}
		}
	}
}

while(action = getch());

return 0;
}

