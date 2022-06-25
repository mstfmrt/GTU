/*Mustafa Mert - 200104004006*/

/*
** hw1_io.c:
**
** The source file implementing output functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/


#include <stdio.h>
#include "hw1_io.h"

void firstTerm(double x,char arr[])/*For first term if it is positive there is no need to write + this is why I used a seperate function*/
{
	if(x == 1){
		printf("%s", arr);
	}
	else if(x == -1){
		printf("-%s",arr);
	}
	else{
		printf("%.f%s", x,arr);
	}
}

void otherTerm(double x,char arr[])/*For other terms there should be sign for both positive and negative*/
{
	if(x == 1){
		printf("+%s", arr);
	}
	else if(x == -1){
		printf("-%s",arr);
	}
	else if (x ==0){
		
	}
	else{
		if (x>0)
		{
			printf("+%.f%s", x,arr);
		}
		else{
			printf("%.f%s", x,arr);
		}
	}
}


void write_polynomial3(double a0, double a1, double a2, double a3)
{
	firstTerm(a0,"x^3");
	otherTerm(a1,"x^2");
	otherTerm(a2,"x");
	otherTerm(a3,"");
	printf("\n");
   
}


void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{
    firstTerm(a0,"x^4");
    otherTerm(a1,"x^3");
	otherTerm(a2,"x^2");
	otherTerm(a3,"x");
	otherTerm(a4,"");
	printf("\n");
}
