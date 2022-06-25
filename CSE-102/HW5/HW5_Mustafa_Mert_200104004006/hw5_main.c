/*Mustafa Mert - 200104004006*/

/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/


#include <stdio.h>
#include "hw5_lib.h"


void test_operate_polynomials () 
{	
	double a3, a2, a1, a0, b3, b2, b1, b0;
	char op;
	printf("Enter first polynomial as (3, a), (2, b), (1, c), (0, d) : ");/*Getting input from user with an order as showed in pdf*/
	scanf(" (3, %lf), (2, %lf), (1, %lf), (0, %lf)", &a3, &a2, &a1, &a0);
	printf("Enter saecond polynomial as (3, a), (2, b), (1, c), (0, d) : ");
	scanf(" (3, %lf), (2, %lf), (1, %lf), (0, %lf)", &b3, &b2, &b1, &b0);
	printf("Enter the operator : ");
	scanf(" %c", &op);
	operate_polynomials(&a3, &a2, &a1, &a0, &b3, &b2, &b1, &b0, op);
	printf("(6, %.1f), (5, %.1f), (4, %.1f), (3, %.1f), (2, %.1f), (1, %.1f), (0, %.1f)\n", a2, a1, a0, b3, b2, b1, b0);/*printing returned coefficents*/
}


void test_four_d_vectors ()
{
	double mean_a0=0.0, mean_a1=0.0, mean_a2=0.0, mean_a3=0.0, longest_distance=0.0;
	int N=5;
	four_d_vectors (&mean_a0, &mean_a1, &mean_a2, &mean_a3, &longest_distance, N);
	printf("Mean a0: %f\nMean a1: %f\nMean a2: %f\nMean a3: %f\nThe longest distance between two points: %f\n\n\n", mean_a0, mean_a1, mean_a2, mean_a3, longest_distance);
}


void test_dhondt_method ()
{
	int partyA=100000, partyB=80000, partyC=30000, partyD=20000, partyE=10000, numberOfSeats=550;
	dhondt_method (&partyA, &partyB, &partyC, &partyD, &partyE, numberOfSeats);
	printf("Party A: %d seat(s).\nParty B: %d seat(s).\nParty C: %d seat(s).\nParty D: %d seat(s).\nParty E: %d seat(s).\n\n\n", partyA, partyB, partyC, partyD, partyE);
}


void test_order_2d_points_cc ()
{
	double x1=0.0, y1=0.0, x2=0.0, y2=0.0, x3=0.0, y3=0.0;
	order_2d_points_cc (&x1, &y1, &x2, &y2, &x3, &y3);
	printf("Counter-Clockwise Order: (%f,%f) - (%f,%f) - (%f,%f)\n\n\n", x1, y1, x2, y2, x3, y3);
}


void test_number_encrypt ()
{
	unsigned char number = 125;
	number_encrypt (&number);
	printf("Encrypted number: %d\n\n\n", number);
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_operate_polynomials ();
	test_four_d_vectors ();
	test_dhondt_method ();
	test_order_2d_points_cc ();
	test_number_encrypt ();
	return (0);
} /* end main */
