/*Mustafa Mert - 200104004006*/

/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
**
*/

#include <stdio.h>
#include "hw1_lib.h"

double f3(double a0, double a1, double a2, double a3, double x)/*Calculates 3degree function with given parameters*/
{
return ((a0*x+a1)*x+a2)*x+a3;
}


double f4(double a0, double a1, double a2, double a3, double a4, double x)/*Calculates 4degree function with given parameters*/
{
return (((a0*x+a1)*x+a2)*x+a3)*x+a4;
}



double integral3(double a0, double a1, double a2, double a3, double xs, double xe, double delta)
{
	double i;
	double sum = 0.0;
	for(i=xs;i<xe;i=i+delta){
		sum = sum + (f3(a0, a1, a2, a3, i)*delta);
	}

    return sum;
}


double integral4(double a0, double a1, double a2, double a3, double a4, double xs, double xe, double delta)
{
    double i;
	double sum = 0.0;
	for(i=xs;i<xe;i=i+delta){
		sum = sum + (f4(a0, a1, a2, a3, a4, i)*delta);
	}

    return sum;
    
}


double root3(double a0, double a1, double a2, double a3, double xs, double xe)/*finds root by checking in given interval*/
{
	
	double i;
	for(i=xs;i<xe;i=i+0.000001){
		

		if(-0.0000001<f3(a0, a1, a2, a3, i) && f3(a0, a1, a2, a3, i)<0.0000001){
			return i;
			
		}
	}
	
}


double root4(double a0, double a1, double a2, double a3, double a4, double xs, double xe)/*finds root by checking in given interval*/
{
    double i;
	for(i=xs;i<xe;i=i+0.000001){
		

		if(-0.0000001<f4(a0, a1, a2, a3, a4, i) && f4(a0, a1, a2, a3, a4, i)<0.0000001){
			return i;
			
		}
	}
}
