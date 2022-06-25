/*Mustafa Mert - 200104004006*/

/*
** hw5_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/

#include <stdio.h>
#include <math.h>
#include "hw5_lib.h"


void operate_polynomials  (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double* b0, char op){	
	double c6, c5, c4, c3, c2, c1, c0;
	if(op == '+'){/*if given operator is + it adds coefficents and return them*/
		c3 = *a3 + *b3;
		c2 = *a2 + *b2;
		c1 = *a1 + *b1;
		c0 = *a0 + *b0;
		*a3 = 0.0;
		*a2 = 0.0;
		*a1 = 0.0;
		*a0 = 0.0;
		*b3 = c3;
		*b2 = c2;
		*b1 = c1;
		*b0 = c0;
	}
	else if(op == '-'){/*if given operator is - it substracts coefficents and return them*/
		c3 = *a3 - *b3;
		c2 = *a2 - *b2;
		c1 = *a1 - *b1;
		c0 = *a0 - *b0;
		*a3 = 0.0;
		*a2 = 0.0;
		*a1 = 0.0;
		*a0 = 0.0;
		*b3 = c3;
		*b2 = c2;
		*b1 = c1;
		*b0 = c0;
	}
	else if(op == '*'){/*if given operator is * it multiplies coefficents and return them*/
		c6 = *a3 * *b3;
		c5 = (*a3 * *b2) + (*a2 * *b3);
		c4 = (*a3 * *b1) + (*a2 * *b2) + (*a1 * *b3);
		c3 = (*a3 * *b0) + (*a2 * *b1) + (*a1 * *b2) + (*a0 * *b3);
		c2 = (*a2 * *b0) + (*a1 * *b1) + (*a0 * *b2);
		c1 = (*a1 * *b0) + (*a0 * *b1);
		c0 = (*a0 * *b0);
		*a3 = 0.0;
		*a2 = c6;
		*a1 = c5;
		*a0 = c4;
		*b3 = c3;
		*b2 = c2;
		*b1 = c1;
		*b0 = c0;
	}
}


void four_d_vectors (double* mean_a0, double* mean_a1, double* mean_a2, double* mean_a3, double* longest_distance, int N){
	double a0, a1, a2, a3, b0, b1, b2, b3, d0, d1, d2, d3, euclidian_distance;
	int counter;
	*longest_distance = 0.0;
	printf("Enter a 4D vector : ");
	counter = 1;
	scanf(" %lf %lf %lf %lf",&a0,&a1,&a2,&a3);
	*mean_a0 += a0;
	*mean_a1 += a1;
	*mean_a2 += a2;
	*mean_a3 += a3;
	
	do{
		printf("Enter a 4D vector : ");
		scanf(" %lf %lf %lf %lf",&b0,&b1,&b2,&b3);
		d0 = a0 - b0;
		d1 = a1 - b1;
		d2 = a2 - b2;
		d3 = a3 - b3;
		if(b0 != -1 && b1 != -1 && b2 != -1 && b3 != -1){/*if input is not -1-1-1-1 it adds to total value to calculate average and calculate distance with last vector*/
			*mean_a0 += b0;
			*mean_a1 += b1;
			*mean_a2 += b2;
			*mean_a3 += b3;
			distance_between_4d_points (d0, d1, d2, d3, &euclidian_distance);
			if(*longest_distance < euclidian_distance)/*if last longest is shorter than new one it changes the longest value*/
				*longest_distance = euclidian_distance;
			counter++;
		}
		a0 = b0;
		a1 = b1;
		a2 = b2;
		a3 = b3;
		
	}while(b0 != -1 && b1 != -1 && b2 != -1 && b3 != -1 && counter < N);/*get inputs until taking N input or user enter -1 -1 -1 -1*/

	*mean_a0 = *mean_a0/(double)counter;/*calculating average for each diametion*/
	*mean_a1 = *mean_a1/(double)counter;
	*mean_a2 = *mean_a2/(double)counter;
	*mean_a3 = *mean_a3/(double)counter;
}


void distance_between_4d_points (double d0, double d1, double d2, double d3, double* euclidian_distance){/*calculating distance between 2 4d vector according to euclidian distance formula*/
	*euclidian_distance = sqrt(d0*d0 + d1*d1 + d2*d2 + d3*d3);
}


void dhondt_method (int* partyA, int* partyB, int* partyC, int* partyD, int* partyE, int numberOfSeats){/*this function calculates the seats for given votes according to dhondt method*/	
	int seatA = 0, seatB = 0, seatC = 0, seatD = 0, seatE = 0,i,max;
	int partyvoteA = *partyA, partyvoteB = *partyB, partyvoteC = *partyC, partyvoteD = *partyD, partyvoteE = *partyE;  
	
	for(i=1; i <= numberOfSeats; i++){/*it checks the largest vote and give them one more seat and keeps going as in dhondt method*/
		if(*partyA >= *partyB && *partyA >= *partyC && *partyA >= *partyD && *partyA >= *partyE){
			seatA ++;
			(*partyA) = partyvoteA / (seatA + 1); 
		}
		else if(*partyB >= *partyA && *partyB >= *partyC && *partyB >= *partyD && *partyB >= *partyE){
			seatB ++;
			(*partyB) = partyvoteB  / (seatB + 1);
		}
		else if(*partyC >= *partyA && *partyC >= *partyB && *partyC >= *partyD && *partyC >= *partyE){
			seatC ++;
			(*partyC) = partyvoteC  / (seatC + 1);
		}
		else if(*partyD >= *partyA && *partyD >= *partyB && *partyD >= *partyC && *partyD >= *partyE){
			seatD ++;
			(*partyD) = partyvoteD  / (seatD + 1);
		}
		else if(*partyE >= *partyA && *partyE >= *partyB && *partyE >= *partyC && *partyE >= *partyD){
			seatE ++;
			(*partyE) = partyvoteE  / (seatE + 1);
		}
	}

	*partyA = seatA;
	*partyB = seatB;
	*partyC = seatC;
	*partyD = seatD;
	*partyE = seatE;

}


void order_2d_points_cc (double* x1, double* y1, double* x2, double* y2, double* x3, double* y3){

}

void number_encrypt (unsigned char* number){
	char b7='0', b6='0', b5='0', b4='0', b3='0', b2='0', b1='0', b0='0';
	get_number_components (*number, &b7, &b6, &b5, &b4, &b3, &b2, &b1, &b0);
	reconstruct_components (number, b7, b6, b5, b4, b3, b2, b1, b0);
}


void get_number_components (unsigned char number, char* b7, char* b6, char* b5, char* b4, char* b3, char* b2, char* b1, char* b0){	/*converts the number binary*/
	if(number >= 128){
		*b7 = '1';
		number = number - 128;
	}
	if(number >= 64){
		*b6 = '1';
		number = number - 64;
	}
	if(number >= 32){
		*b5 = '1';
		number = number - 32;
	}
	if(number >= 16){
		*b4 = '1';
		number = number - 16;
	}
	if(number >= 8){
		*b3 = '1';
		number = number - 8;
	}
	if(number >= 4){
		*b2 = '1';
		number = number - 4;
	}
	if(number >= 2){
		*b1 = '1';
		number = number - 2;
	}
	if(number >= 1){
		*b0 = '1';
		number = number - 1;
	}
}


void reconstruct_components (unsigned char* number, char b7, char b6, char b5, char b4, char b3, char b2, char b1, char b0){/*I shuffled components at a time as it given in the pdf then convert same time to decimal */
	*number = 0;
	if(b0 == '1')
		*number += 128;
	if(b1 == '1')
		*number += 64;
	if(b6 == '1')
		*number += 32;
	if(b7 == '1')
		*number += 16;
	if(b4 == '1')
		*number += 8;
	if(b5 == '1')
		*number += 4;
	if(b2 == '1')
		*number += 2;
	if(b3 =='1')
		*number += 1;
}
