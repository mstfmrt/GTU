/*Mustafa Mert - 200104004006*/

#include <stdio.h>
#include <math.h>

void calculate_fibonacci_sequence(){/*prints fibonacci sequance terms for given input*/
	int input,i;
	long long int a,b,temp;
	char control;
	printf("Please enter term(s) number: ");
	do{
		
		scanf("%d",&input);
		control = getchar();

		if(control == '\n'){
			if(input<1){
				printf("Please enter 'positive' term(s) number:");/*if input is not positive it warns for true input*/
			}

			else{
				a=1;
				b=1;
				printf("%lld\n", a);
				for(i=2 ; i<=input ; i++){/*this for block prints fibonacci sequance terms for given input*/
					printf("%lld\n", b);
					temp = b;
					b = a+b;
					a = temp;
				}
				printf("Please enter term(s) number: ");
			}

		}
		else if(control == '*'){/*checks if input '*' do nothing and get out of the loop*/

		}

		else
			printf("Please enter 'numeric' term(s) number: ");/*if input is not numeric it warns for true input*/
	}while(control != '*');/*function is keep working until input is not equal to '*' */
}



void decide_perfect_harmonic_number(){/*decides if input perfect numbert or harmonic divisor*/
	double   perf_total, har_total, div_counter;
	int i, input;
	char control;
	
 	

 	do{
 		div_counter = 0;
 		har_total=0;
 		perf_total=0;
		printf("Please enter input number: ");
		scanf("%d",&input);
		control = getchar();

		if(control == '\n'){
			for (i = 1; i < input ; i++){/*checks for all nubur until input if number is divisor of input or not*/
					if(input%i == 0.0){
						perf_total += i;
						har_total += 1.0/i;
						div_counter++;
					}
				}

			har_total += 1.0/input;
			div_counter++;
			

			printf("Is Perfect Number? : ");
			if(perf_total==input)/*Checking if the input Perfect number with given formula in homework pdf*/
				printf("Yes\n");
			else
				printf("No\n");


			printf("Is Harmonic Divisor Number? : ");
			if(fmod((float)(div_counter/har_total),1.0) == 0)/*Checking if the input harmonic divisor with given formula in homework pdf*/
				printf("Yes\n");
			else
				printf("No\n");

		}

	}while(control != '*');/*function is keep working until input is not equal to '*' */
}



			



void differance_max_min(){/*Get inputs from user and compare them to find max and min. Then calculates their differace*/
	int i;
	double a,max, min;
	printf("Please enter 5 numbers: \n");
	scanf("%lf",&a);
	max = a;
	min = a;
	for ( i =1 ; i <= 4; i++)
	{
		scanf("%lf",&a);/*checks if new input largest or smallest*/
		if(max<a)
			max=a;
		if(min>a)
			min=a;	
	}
	printf("Maximum number is: %g\n", max);
	printf("Minimum number is: %g\n", min);
	printf("Differance between maximum and minimum is %g \n", max-min);
}


void bmi_calculation(){/*Calculates Body Mass Index and return your bmi type*/
	double  weight, height, BMI;
	
	printf("Please enter you weight in kg: ");
	scanf("%lf",&weight);

	printf("Please enter you height in meters: ");
	scanf("%lf",&height);
	BMI = weight / (height*height);/*Calculates Body Mass index according to given formula in homework pdf*/
	
	if(BMI<16.0)
		printf("Your category: Severely Underweight\n");
	else if(BMI>=16.0 && BMI<18.5)
		printf("Your category: Underweight\n");
	else if(BMI>=18.5 && BMI<25)
		printf("Your category: Normal\n");
	else if(BMI>=25.0 && BMI<30)
		printf("Your category: OwerWeight\n");
	else if(BMI>=30)
		printf("Your category: Obese\n");

}




int main() {

	printf("\n-----------PART 1-----------\n");
	calculate_fibonacci_sequence();
	printf("\n----------------------------\n");
	printf("\n-----------PART 2-----------\n");
	decide_perfect_harmonic_number();
	printf("\n----------------------------\n");
	printf("\n-----------PART 3-----------\n");
	differance_max_min();
	printf("\n----------------------------\n");
	printf("\n-----------PART 4-----------\n");
	bmi_calculation();
	printf("\n----------------------------\n");
	return (0);
}