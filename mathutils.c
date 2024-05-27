/* Number Utilities Program 
 * Written by Oscillator
 * Just some useful math computation functions */

#include <stdio.h>
#include <stdlib.h>


/* Set Values
 * Takes in a positive integer and returns 
 * an array of all numbers less than or equal 
 * to the input */
int* set_values(int input){
	int j = 0;
	int * int_set = (int*)malloc(sizeof(int));
	while (j < input){
		int_set[j] = j+1;
		printf("%d ", int_set[j]);
		j += 1;
		int_set = (int*)realloc(int_set, sizeof(int)*(j+1));
	}
	return int_set;
}

/* Prime Factors
 * Takes a positive integer and returns
 * its prime factors */
int* prime_factors(int input){
	int j = 2;
	int prime_counter = 0;
	int * prime_factor_set = (int*)malloc(sizeof(int));
	while (j < input){ 
		if (input % j == 0){
				prime_factor_set[prime_counter] = j;
				/*printf("%d ", prime_factor_set[prime_counter]);*/
				prime_counter += 1;
				prime_factor_set = (int*)realloc(prime_factor_set, sizeof(int)*(prime_counter+1));
				j += 1;
		}
		else {
			j += 1;
		}
	}
	return prime_factor_set;
}

/* Sub Primes
 * Takes in a positive integer and returns an array
 * of all the prime numbers that are less than or
 * equal to the input */
int* sub_primes(int input){
	int* i;
	int j = 2;
	int prime_counter = 0;
	int * prime_set = (int*)malloc(sizeof(int));
	while (j <= input){
		i = prime_factors(j);
		if (i[0] > 0){
			j += 1;
		}
		else{
			prime_set[prime_counter] = j;
			printf("%d ", prime_set[prime_counter]);
			prime_counter += 1;
			prime_set = (int*)realloc(prime_set, sizeof(int)*(prime_counter+1));
			j += 1;
		}
	}
	return prime_set;
}





int main(){
	int j;
	printf("Input a number to find prime factors: ");
	scanf("%d ", &j);
	sub_primes(j);
}
