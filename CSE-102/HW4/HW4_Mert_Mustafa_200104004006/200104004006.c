/*Mustafa Mert - 200104004006*/

#include <stdio.h>
#include <math.h>

void firstTerm(double coef,int i){/*this function prints coefficent for first term in a pretty format*/
	if(coef == 1)
			printf("x^%d", i);
	else if(coef == -1)
		printf("-x^%d", i);
	else if (coef ==0){}
	else
		printf("%.1f^%d", coef, i);	/*in homework forum there is little confusion about rounding, I did it for one digit and standart mathematical rounding rules. I did all roundings like this*/	
}

void otherTerm(double coef,int i){/*this function prints coefficent for other than first term in a pretty format*/

	if(i==1){/*if degree is 1 there shouldn't be a  power printg*/
		if(coef == 1)/*if coefficent is 1 for a pretty format there shouldn'n be a number*/
			printf("+x");
		else if(coef == -1)
			printf("-x");
		else if (coef ==0){}/*if coefficent is 0 for a pretty format there shouldn'n be a number and x*/ 
		else{                     /*it keeps going like that for other conditions*/
			if (coef>0)
				printf("+%.1fx", coef); 
			else
				printf("%.1fx", coef);
		}
	}

	else if(i==0){/*if degree is 0 there should be only coefficent without x*/

		if (coef ==0){}
		else{
			if (coef>0)
				printf("+%.1f", coef);
			else
				printf("%.1f", coef);
		
		}
	}

	else{
		if(coef == 1)
			printf("+x^%d", i);
		else if(coef == -1)
			printf("-x^%d", i);
		else if (coef == 0){}
		else{
			if (coef>0)
				printf("+%.1f^%d", coef, i);
			else
				printf("%.1f^%d", coef, i);
		}	
	}
}

int is_armstrong(int input){/*this function checks if the input is armstrong number or not according to given info in the pdf than returns 1 or 0*/
	int i,total,temp,r;
	temp = input;
	total = 0;
	i = 0;
	while(temp!=0){
		i = temp%10;
		total += i*i*i;
		temp = temp/10;
	}
	if(input == total)
		r = 1;

	else
		r = 0;

	return r;
}

int is_palindrome(int input){/*this function checks if the input is palindrome number or not according to given info in the pdf than returns 1 or 0*/
	int temp,reverse, i,r;
	reverse = 0;
	temp = input;

	while(temp!=0){
		i = temp%10;
		reverse = reverse*10 + i;
		temp = temp/10;
	}
	if(input == reverse)
		r = 1;
	else
		r = 0;
	return r;
}


void print_polynomial(){/*this function prints a polynomial in pretty format with given degree and coefficents*/
	int i,degree;
	double  coef;
	printf("Enter your polynomial [n a_n a_n-1 a_n-2 ... a_0]: ");
	scanf("%d",&degree);

	for ( i = degree; i >= 0 ; i--)
	{
		scanf("%lf", &coef);
		if(coef < 0.05 && coef > -0.05)
			coef = 0.0;

		coef = round(coef*10)/10; /*I rounded numbers before send with function for better result*/

		if(i == degree)/*it checcks if it is first term for given degree*/
			firstTerm(coef,i);
		else
			otherTerm(coef,i);

	}
	printf("\n");
}

void armstrong_palindrome_checker(){
	int input;
	printf("Plese enter a positive integer number : ");
	do{
		scanf("%d", &input);
		if(input < 0)/*if given input is negative it gives an error message and waiting for a new input*/
			printf("\nPlease enter positive number: ");
	}while(input < 0);

	if(is_armstrong(input)==1 && is_palindrome(input)==0)
		printf("This number is only Armstrong number.\n");
	else if(is_armstrong(input)==0 && is_palindrome(input)==1)
		printf("This number is only Palindrome number.\n");
	else if(is_armstrong(input)==1 && is_palindrome(input)==1)
		printf("This number is both Palindrome and Armstrong number.\n");
	else if(is_armstrong(input)==0 && is_palindrome(input)==0)
		printf("This number does not satisfy any special cases.\n");

}

void sum_primes_between(){/*this function finds prime numbers between given inputs then add them all*/
	int inputA, inputB, temp, i, j, count, is_prime,total;
	total = 0;
	printf("Please enter first integer number: ");
	do{
		scanf("%d", &inputA);
		if(inputA < 0)/*if given input is negative it gives an error message and waiting for a new input*/
			printf("\nPlease enter positive number: ");
	}while(inputA < 0);

	printf("Please enter second integer number: ");
	do{
		scanf("%d", &inputB);
		if(inputB < 0)/*if given input is negative it gives an error message and waiting for a new input*/
			printf("\nPlease enter positive number: ");
	}while(inputB < 0);

	if(inputA>inputB){/*checks if first input bigger than second one replace them*/
		temp = inputA;
		inputA = inputB;
		inputB = temp;	
	}

	for (i = inputA+1; i < inputB; i++){
		if(i == 1)
			is_prime= 0;
		else 
			is_prime = 1;

		for(j=2 ; j < i; j++)/*checking all numbers between given inputs*/
			if(i % j == 0)/*checking if number prime or not*/
				is_prime = 0;
		
		if(is_prime == 1)
			total += i;
		
	}
	printf("Sum of prime numbers between %d and %d : %d\n", inputA, inputB, total);

}

int main(int argc, char const *argv[])
{
	printf("\n\n\n----- print_polynomial started -----\n\n");
	print_polynomial();
	printf("\n\n\n----- armstrong_palindrome_checker started -----\n\n");
	armstrong_palindrome_checker();
	printf("\n\n\n----- sum_primes_between started -----\n\n");
	sum_primes_between();

	return 0;
}