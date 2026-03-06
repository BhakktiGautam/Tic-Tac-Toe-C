#include<stdio.h>
//3*3 board fot Tic Tac Toe
char board[3][3];

//Function to initialize the board with members 1-9
void initializeboard()
{
char ch='1';
for(int i=0;i<3;i++)
{
for( int j=0;j<3;j++)
{
	board[i][j]=ch++;//Fill board with position numbers
}
}
}

//Function to print the current board  
void printboard()
{
	printf("\n");
	for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
printf(" %c",board[i][j]);//Print each board cell

//Print vertical separator except after last column
if(j<2)
{
printf("|");
}
}
printf("\n");
  printf("\n");

	/* Print horizontal separator except after last row */
        if(i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

/* Function to check if any player has won */
int checkwin()
{

/* Check rows */
for(int i=0;i<3;i++)
{
	if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])
	return 1;
}

/* Check columns */
for(int i=0;i<3;i++)
{
	if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
	return 1;
}

/* Check main diagonal */
for(int i=0;i<3;i++)
{
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
	return 1;
}
/* Check second diagonal */
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return 1;
/* No winner */
return 0;
}

/* Function to check if the match is a draw */
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
return 1;// Board full → draw
}
int main()
{
int position;
int player=1;	 // Player 1 starts
char put;       // Symbol to place on board

/* Initialize board */
initializeboard();

/* Game loop */
while(1)
{
	printboard();
	 /* Assign symbol depending on player */
	put=(player==1)?'X':'O';
printf("player %d,enter position: ",player);
scanf("%d",&position);

 /* Validate input position */
if(position < 1 || position > 9)
{
    printf("Invalid input!\n");
    continue;
}

/* Convert position (1-9) into row and column */
int row=(position-1)/3;
int column=(position-1)%3;

 /* Check if cell is empty */
if(board[row][column]!='X'&&board[row][column]!='O'){
board[row][column]=put;
}
else
{
printf("Invalid Move .Try again.\n");
continue;
}

/* Check if someone won */
if(checkwin())
{
printboard();
printf("Player %d wins\n",player);
break;
}

/* Check for draw */
if(isDraw())
{
    printboard();
    printf("It's a draw!\n");
    break;
}

 /* Switch player */
player=(player==1)?2:1;
}
return 0;

}
