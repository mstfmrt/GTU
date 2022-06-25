/*Mustafa Mert - 200104004006*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int c0=0, c1=0, c2=0, c3=0, c4=0; /*counter for labels*/

typedef struct /*defining a struct type for bank labeling system*/
{
	char name[20];
	int age;
	int label;
}customer;

void print_secuence(customer arr[5][250]){/*this function prints the current secuence for the time that called*/
	int x0=0, x1=0, x2=0, x3=0, x4=0;
	int i,j;
	printf("Current Secuence: ");
	for(i=0;i<50;i++){/*this parts prints the secuence according to given algorithm in pdf*/
		for(j=0;j<5;j++){
			if(arr[0][x0].label!=-1)
				printf("%d-",arr[0][x0].label);
			x0++;
		}
		for(j=0;j<3;j++){
			if(arr[1][x1].label!=-1)
				printf("%d-",arr[1][x1].label);
			x1++;
		}
		for(j=0;j<3;j++){
			if(arr[2][x2].label!=-1)
				printf("%d-",arr[2][x2].label);
			x2++;
		}
		for(j=0;j<2;j++){
			if(arr[3][x3].label!=-1)
				printf("%d-",arr[3][x3].label);
			x3++;
		}
		for(j=0;j<2;j++){
			if(arr[4][x4].label!=-1)
				printf("%d-",arr[4][x4].label);
			x4++;
		}
	}
	printf("\n");
}


void add_customer(customer arr[5][250]){/*this function adds customer*/
	char name[20];
	int age, label;
	printf("\n\nPlease enter the name of the customer : ");/*entering information about customer*/
	scanf("%s",name);
	printf("Please enter the age of the customer : ");
	scanf("%d",&age);
	printf("Please enter the label of the customer : ");
	scanf("%d",&label);/*according to his/her label add him/her to secuence*/
	if(label==0){
		strcpy(arr[0][c0].name,name);
		arr[0][c0].age = age;
		arr[0][c0].label = label;
		c0++;
	}
	else if(label==1){
		strcpy(arr[1][c1].name,name);
		arr[1][c1].age = age;
		arr[1][c1].label = label;
		c1++;
	}
	else if(label==2){
		strcpy(arr[2][c2].name,name);
		arr[2][c2].age = age;
		arr[2][c2].label = label;
		c2++;
	}
	else if(label==3){
		strcpy(arr[3][c3].name,name);
		arr[3][c3].age = age;
		arr[3][c3].label = label;
		c3++;
	}
	else if(label==4){
		strcpy(arr[4][c4].name,name);
		arr[4][c4].age = age;
		arr[4][c4].label = label;
		c4++;
	}
}


void process_customer(customer arr[5][250]){/*this function process the first customer according to current sequence*/
	int x0=0, x1=0, x2=0, x3=0, x4=0;
	int i,j;
	for(i=0;i<50;i++){
		for(j=0;j<5;j++){
			if(arr[0][x0].label!=-1){
				arr[0][x0].label = -1;
				return;
			}
			x0++;
		}
		for(j=0;j<3;j++){
			if(arr[1][x1].label!=-1){
				arr[1][x1].label=-1;
				return;
			}
			x1++;
		}
		for(j=0;j<3;j++){
			if(arr[2][x2].label!=-1){
				arr[2][x2].label=-1;
				return;
			}
			x2++;
		}
		for(j=0;j<2;j++){
			if(arr[3][x3].label!=-1){
				arr[3][x3].label=-1;
				return;
			}
			x3++;
		}
		for(j=0;j<2;j++){
			if(arr[4][x4].label!= -1){
				arr[4][x4].label=-1;
				return;
			}
			x4++;
		}
	}
}


int main(int argc, char const *argv[])
{
	int choose, i, j;
	customer customers[5][250];/*creating an customer type array*/
	for(i=0;i<5;i++){
		for(j=0;j<250;j++){
			customers[i][j].label = -1;
		}
	}
	printf("***********Banking System***********\n");
	while(1){
		print_secuence(customers);
		printf("1-Add customer\n");
		printf("2-Process customer\n");
		printf("Press any other number to Exit\n");
		scanf("%d",&choose);

		if(choose==1)
			add_customer(customers);
		else if(choose==2)
			process_customer(customers);
		else
			break;
		system("clear");/*clears the console for better view*/
		}
	
	return 0;
}