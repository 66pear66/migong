#include <stdio.h>
#include <windows.h>
int i;
char t;
#define ROW 9
#define COL 11
char map[ROW][COL+1]={
	{"*#*********"},
	{"***###*###*"},
	{"###**#****#"},
	{"*#**###**#*"},
	{"***********"},
	{"#####*##*##"},
	{"**#*****#*E"},
	{"***#*###**#"},
	{"*#*********"},
};

void print_map()
{
	for(i=0;i<ROW;i++)
	{
		puts(map[i]);
	}
}

void show_cursor(int curX,int curY)
{
	COORD pos;
	pos.X=curX;
	pos.Y=curY;
	printf("curX=%d,cur=%d\n",curX,curY);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int curX,curY;
int main()
{
	while(1)
	{
	system("cls");
	print_map();
	show_cursor(curX,curY);
	
	t=getch();
	if(t=='w')
	{
		//向上走
		if((curY-1)>=0&&(map[curY-1][curX]=='*'||map[curY-1][curX]=='E')) curY--;
	}
	else if(t=='s')
	{
		//向下走
		if((curX-1)<ROW&&(map[curY+1][curX]=='*'||map[curY+1][curX]=='E')) curY++;
	}
	else if(t=='a')
	{
		//向左走
		if((curX-1)>0&&(map[curY][curX-1]=='*'||map[curY][curX-1]=='E')) curX--;
	}
	else if(t=='d')
	{
		//向右走
		if((curX+1)<COL&&(map[curY][curX+1]=='*'||map[curY][curX+1]=='E')) curX++;
	}
	if(map[curY][curX]=='E')
	{
		printf("Congratulations,you win.Excellent!\n");
		break;
	}
}
}