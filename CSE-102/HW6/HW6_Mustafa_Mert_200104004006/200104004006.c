/*Mustafa Mert - 200104004006*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 3
enum towards{left, right, up, down};/*enumarated definition for directions*/

void create_puzzle(int arr[N][N]){/*creates the shuffled puzzle for defined N*/
	int i,j,x,a,b,temp;
	x=0;
	for(i=0;i<N;i++){/*creates in an order*/
		for(j=0;j<N;j++){
			arr[i][j] = x;
			x++;
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){/*then shuffles array*/
			a = rand()%N;
			b = rand()%N;
			temp = arr[a][b];
			arr[a][b] = arr[i][j];
			arr[i][j] = temp;
		}
	}
}
void print_puzzle(int arr[N][N]){/*prints puzzle in a proper form for defined dimentions*/
	int i, j,k;
	printf("\n\n*");
	for(i=0;i<N;i++){
		printf("*****");
	}
	printf("\n");
	for(i=0;i<N;i++){\
		printf("*");
		for(j=0;j<N;j++){
			if(arr[i][j] == 0){
				printf("    *");
			}
			else{
				printf(" %2d *", arr[i][j]);
			}
		}
		printf("\n*");
		for(k=0;k<N;k++){
			printf("*****");
		}
		printf("\n");
	}	
}
int is_solved(int arr[N][N]){/*checks if puzzle solved or not. If it is it turns 1, if not it returns 0*/
	int i, j, x, isSolved;
	isSolved = 1;
	x=1;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(arr[i][j]!=x && i != N-1 && j != N-1)
				isSolved = 0;
		}
	}
	return isSolved;
}
void move(int arr[N][N], int direction, int row, int column){/*controls the movements for given parameters*/
	int isValid = 0,i,j;

	switch(direction){
	case left:/*if selected direction is left it checks is there a free space left of the selected position*/
		for(i=column-1;i>=0;i--){
			if(arr[row][i]==0){
				isValid=1;
				break;
			}
		}
		if(isValid==1){/*if there is free space it slides the elements to there*/
			for(j=i;j<column;j++){
				arr[row][j]=arr[row][j+1];
			}
			arr[row][column]=0;
		}
		if(isValid==0)/*if there is no free space it gives an error*/
			printf("Move you wanted is invalid!\n");
		break;

	case right:/*if selected direction is right it checks is there a free space right of the selected position*/
		for(i=column+1;i<N;i++){
			if(arr[row][i]==0){
				isValid=1;
				break;
			}
		}
		if(isValid==1){/*if there is free space it slides the elements to there*/
			for(j=i;j>column;j--){
				arr[row][j]=arr[row][j-1];
			}
			arr[row][column]=0;
		}
		if(isValid==0)/*if there is no free space it gives an error*/
			printf("Move you wanted is invalid!\n");
		break;

	case up:/*if selected direction is up it checks is there a free space up side of the selected position*/
		for(i=row-1;i>=0;i--){
			if(arr[i][column]==0){
				isValid=1;
				break;
			}
		}
		if(isValid==1){/*if there is free space it slides the elements to there*/
			for(j=i;j<row;j++){
				arr[j][column]=arr[j+1][column];
			}
			arr[row][column]=0;
		}
		if(isValid==0)/*if there is no free space it gives an error*/
			printf("Move you wanted is invalid!\n");
		break;

	case down:/*if selected direction is down it checks is there a free space down side of the selected position*/
		for(i=row+1;i<N;i++){
			if(arr[i][column]==0){
				isValid=1;
				break;
			}
		}
		if(isValid==1){/*if there is free space it slides the elements to there*/
			for(j=i;j>row;j--){
				arr[j][column]=arr[j-1][column];
			}
			arr[row][column]=0;
		}
		if(isValid==0)/*if there is no free space it gives an error*/
			printf("Move you wanted is invalid!\n");
		break;
	default:
		printf("Move you wanted is invalid!\n");
		break;
	}
}

int main(int argc, char const *argv[])
{
	int puzzle[N][N], i ,j,direction,isGiveUp=0;/*creating array and defining some variables*/
	create_puzzle(puzzle);

	printf("\n*******************************\n");	
	printf("****WELCOME TO SLIDE PUZZLE****\n");
	printf("*******************************\n");
	print_puzzle(puzzle);

	do{
		printf("Enter the movement you want to make [row column direction]: ");
		scanf("%d %d %d",&i,&j,&direction);
		if(i==-1 && j== -1){/*if user want to gave up input position should be (-1,-1) */
			isGiveUp =1;
			printf("You gave up see you next time :)\n");
		}
		else if(i<0 || i>=N || j<0 || j>=N || direction<0 || direction>3)/*if users position inputs are not in invalid range it gives an error*/
			printf("Move you wanted is invalid!\n");
		else{
			move(puzzle,direction,i,j);
			print_puzzle(puzzle);
			if(is_solved(puzzle)==1)/*if user solves it shows a winning message*/
				printf("\n\n  !!!YOU WON!!!\n\n");
		}
		printf("\n\n");
	}while(is_solved(puzzle)!=1 && isGiveUp!=1);/*it wants an input from user until user win or give up*/

	
	return 0;
}