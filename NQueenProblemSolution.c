/*
 ============================================================================
 Name        : 01.c
 Created on  : Jan 16, 2020
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<string.h>
#define N 4
static char flag=0;
void printboard(int[][N],int); //for printing board at any time
void firstsolutiononly(int[][N],int); //for getting first and only solution
int issafe(int[][N],int,int); //to check if it safe to place queen at specific location
int main(void)
{
	int board [N][N]; //board declaration
	memset(board,0,sizeof(board)); //to fill the board with zeros
	firstsolutiononly(board,0); //get the first and only solution
	return 0;
}
void printboard(int board[][N],int n)
{
	int row,column;
	for(row=0;row<n;row++) //start from row Zero to row n get every element in each column
	{
		for(column=0;column<n;column++) //start from column Zero to column n in each row
		{
			printf("%d ",board[row][column]); // print each element
			fflush(stdout);
		}
		printf("\n"); //after each row print new line
		fflush(stdout);
	}
}
void firstsolutiononly(int board[][N],int column)
{
	if(column>=N) // if N queens are placed successfully so print the solution and make set solution flag
	{
		printboard(board,N);
		flag=1; // after finding the first solution Now set the flag to trigger the stopping process of the recursion
		return;
	}
	else
	{
			int row=0;
			for(row=0;row<N;row++) //start checking each row in the current column
			{
				if((issafe(board,row,column)==1)&&(flag!=1)) //if it safe to place queen here and no solution is founded yet
				{
					board[row][column]=1; //place queen on current row and column
					firstsolutiononly(board,column+1); //recur for next column
					if(flag!=1) //don't backtrack if one solution already founded
					{
						board[row][column]=0; //backtrack and remove queen from current location
					}
				}
			}
	}
}
int issafe(int board[][N],int row,int column)
{
	int colindex,rowindex;
	for(colindex=0;colindex<column;colindex++) //check for the left side columns
	{
		if(board[row][colindex]==1)
		{
			return 0;
		}
		else
		{
			continue;
		}
	}
	for(colindex=column,rowindex=row;(colindex>=0)&&(rowindex>=0);colindex--,rowindex--) //check for the \ diagonal
	{
		if(board[rowindex][colindex]==1)
		{
			return 0;
		}
		else
		{
			continue;
		}
	}
	for(colindex=column,rowindex=row;(colindex>=0)&&(rowindex<N);colindex--,rowindex++) //check for the / diagonal
	{
		if(board[rowindex][colindex]==1)
		{
			return 0;
		}
		else
		{
			continue;
		}
	}
	return 1;
}
