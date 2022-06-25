/*Mustafa Mert - 200104004006*/

/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
*/

#include <stdio.h>
#include <math.h>
#include "hw2_lib.h"

int isLeap(int year){/*Checks whether the year is leap year or not*/
	if(year%4==0){
		if(year%100==0){
			if(year%400==0){
				return 1;
			}
			else 
				return 0;
		}
		else 
			return 1;
	}
	else 
		return 0;
}

int dayBeforeMonth(int month,int year){/*Returns amount of day before the given month*/

	int n;

	if(month == 1)
		n=0;
	else if(month == 2)
		n=31;
	else if(month == 3)
		n=59;
	else if(month == 4)
		n=90;
	else if(month == 5)
		n=120;
	else if(month == 6)
		n=151;
	else if(month == 7)
		n=181;
	else if(month == 8)
		n=212;
	else if(month == 9)
		n=243;
	else if(month == 10)
		n=273;
	else if(month == 11)
		n=304;
	else if(month == 12)
		n=334;

	if(isLeap(year) && month>2)
		n = n+1;

	return n;
}

int dayBeforeDate(int day, int month, int year){/*Calculates how many days passed since christ*/
	
	return (year-1)*365.242199 + dayBeforeMonth(month,year) + day ;
}


int find_weekday_of_data(int day, int month, int year)
{
	int n;
	if(day<1||month<1||year<1){/*checks invalid dates for giving error*/
		printf("invalid date\n");
		return -111;
	}
	else if(month>12){
		printf("invalid date\n");
		return -111;
	}
	else if(day>31){
		printf("invalid date\n");
		return -111;
	}
	else if(month==2 && day>29){
		printf("invalid date\n");
		return -111;
	}
	else if(month==2 && day>28 && !isLeap(year)){
		printf("invalid date\n");
		return -111;
	}




	else{
		if((dayBeforeDate(day,month,year)+1)%7==0)/*takes mod of day amount before dates to find weekday*/
			n=7;
		else
			n = (dayBeforeDate(day,month,year)+1)%7;

    	return n;
	}		

	
}


int count_day_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year)/*Calculates how many days passed since christ for given dates and finds the days between */
	
{	
	int dayBetween;
	if(start_day<1||start_month<1||start_year<1){/*checks invalid dates for giving error*/
		printf("invalid date\n");
		return -111;
	}
	else if(start_month>12){
		printf("invalid date\n");
		return -111;
	}
	else if(start_day>31){
		printf("invalid date\n");
		return -111;
	}
	else if(start_month==2 && start_day>29){
		printf("invalid date\n");
		return -111;
	}
	else if(start_month==2 && start_day>28 && !isLeap(start_year)){
		printf("invalid date\n");
		return -111;
	}
	if(end_day<1||end_month<1||end_year<1){/*checks invalid dates for giving error*/
		printf("invalid date\n");
		return -111;
	}
	else if(end_month>12){
		printf("invalid date\n");
		return -111;
	}
	else if(end_day>31){
		printf("invalid date\n");
		return -111;
	}
	else if(end_month==2 && end_day>29){
		printf("invalid date\n");
		return -111;
	}
	else if(end_month==2 && end_day>28 && !isLeap(end_year)){
		printf("invalid date\n");
		return -111;
	}



	else{
		dayBetween = dayBeforeDate(end_day,end_month,end_year) - dayBeforeDate(start_day,start_month,start_year);
    	return dayBetween;
	}

    
}


double find_angle(double a, double b, double c)
{
	double m, k, cosa;
	m = sqrt(((a*a)+(c*c)-(b*b/2.0))/2.0)/3.0;		/*formula that I used for solving given problem in the task*/
	k = sqrt(((a*a)+(b*b)-(c*c/2.0))/2.0)/3.0;
	cosa = ((a*a) - (4.0*k*k) - (4.0*m*m))/(8.0*k*m);

    return 3.14159265-acos(cosa);
}


void print_tabulated(unsigned int r11, double r12, int r13, /*tabulates given values by user*/
                     unsigned int r21, double r22, int r23, 
                     unsigned int r31, double r32, int r33, char border)
{

printf("┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓\n");/*I used special characters for better view*/
printf("┃    Row 101    ┃  Row ABCDEFG  ┃  Row XYZ123   ┃\n");
printf("┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫\n");
printf("┃\t%d\t┃%g\t\t┃%d\t\t┃\n",r11,r12,r13);
printf("┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫\n");
printf("┃\t%d\t┃%g\t\t┃%d\t\t┃\n",r21,r22,r23);
printf("┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫\n");
printf("┃\t%d\t┃%g\t\t┃%d\t\t┃\n",r31,r32,r33);
printf("┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┛\n");




}

