\#include<stdio.h>
char board[3][3];

void initializeboard()
{
char ch='1';
for(int i=0;i<3;i++)
{
for( int j=0;j<3;j++)
{
	board[i][j]=ch++;
}
}
}
void printboard()
{
	printf("\n");
	for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
printf(" %c",board[i][j]);
if(j<2)
{
printf("|");
}
}
printf("\n");
  printf("\n");
        if(i < 2) printf("---|---|---\n");
    }
    printf("\n");
}
int checkwin()
{
for(int i=0;i<3;i++)
{
	if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])
	return 1;
}
for(int i=0;i<3;i++)
{
	if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
	return 1;
}
for(int i=0;i<3;i++)
{
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
	return 1;
}

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return 1;

return 0;
}
int isDraw()
{	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]!='X'&& board[i][j]!='O')
			return 0;
		}
	}
return 1;
}
int main()
{
int position;
int player=1;
char put;
initializeboard();
while(1)
{
	printboard();
	put=(player==1)?'X':'O';
printf("player %d,enter position: ",player);
scanf("%d",&position);
if(position < 1 || position > 9)
{
    printf("Invalid input!\n");
    continue;
}
int row=(position-1)/3;
int column=(position-1)%3;
if(board[row][column]!='X'&&board[row][column]!='O'){
board[row][column]=put;
}
else
{
printf("Invalid Move .Try again.\n");
continue;
}
if(checkwin())
{
printboard();
printf("Player %d wins\n",player);
break;
}
if(isDraw())
{
    printboard();
    printf("It's a draw!\n");
    break;
}
player=(player==1)?2:1;
}
return 0;
}