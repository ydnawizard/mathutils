/* Number Utilities Program 
 * Written by Oscillator
 * Just some useful math computation functions */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Initialize size variables 
 * for dynamic arrays */
int set_size;
int prime_factors_size;
int sub_primes_size;
int next_primes_size;

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
	set_size = j - 1;
	return int_set;
}

/* Is Prime
 * Takes in a positive integer and returns
 * 1 if its prime and 0 otherwise */
int is_prime(int input){
	int i = 2;
	int isPrime;
	while (i <= input){
		if (input == 2){
			isPrime = 1;
			return isPrime;
		}
		else if (input - i == 1){
			isPrime = 1;
			return isPrime;
		}
		else if (input % i == 0){
			isPrime = 0;
			return isPrime;
		}
		else{
			i += 1;
		}
	}
}


/* Prime Factors
 * Takes a positive integer and returns
 * its prime factors */
int* prime_factors(int input){
	int j = 2;
	int prime_counter = 0;
	int * prime_factor_set = (int*)malloc(sizeof(int));
	while (j < input){ 
		if ((input % j == 0) && (is_prime(j) == 1)){
				prime_factor_set[prime_counter] = j;
				prime_counter += 1;
				prime_factor_set = (int*)realloc(prime_factor_set, sizeof(int)*(prime_counter+1));
				j += 1;
		}
		else {
			j += 1;
		}
	}
	prime_factors_size = prime_counter - 1;
	return prime_factor_set;
}




/* Sub Primes
 * Takes in a positive integer and returns an array
 * of all the prime numbers that are less than or
 * equal to the input. Leverages the property
 * that a number is either prime or has a prime
 * factorization.*/
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
			prime_counter += 1;
			prime_set = (int*)realloc(prime_set, sizeof(int)*(prime_counter+1));
			j += 1;
		}
	}
	sub_primes_size = prime_counter - 1;
	return prime_set;
}


/* Next Prime
 * Takes in a positive integer and returns the 
 * the closest prime number that is greater than
 * or equal to the input */
int next_prime(int input){
	int prime;
	int i = 0;
	input = input + 1;
	int* factors = prime_factors(input);
	while (i != -1){
		if(factors[0] > 0){
			input += 1;
			factors = prime_factors(input);
		}
		else{
			prime = input;
			i = -1;
		}
	}
	return prime;
}

/* Next Primes
 * Takes in two positive integers input and n,
 * and returns the next n prime numbers from input*/
int* next_primes(int input, int n){
	int i = 0;
	int* primes = (int*)malloc(sizeof(int));
	while (i < n){
		if (primes[0] == 0){
			primes[i] = next_prime(input);
			i += 1;
		}
		else{
			primes[i] = next_prime(primes[i-1]);
			i += 1;
		}
	}
	next_primes_size = i - 1;
	return primes;
}


int main(char argc, char* argv[]){
	int opt;
	int* result = (int*)malloc(sizeof(int));
	while((opt = getopt(argc, argv, ":f:s:n")) != -1){
		switch(opt){
			case 's':
				result = sub_primes(strtol(argv[2], NULL, 10));
				for(int i = 0; i <= sub_primes_size; i++){
					printf("%d ", result[i]);
				}
				break;
			case 'f':
				result = prime_factors(strtol(argv[2], NULL, 10));
				for(int i = 0; i <= prime_factors_size; i++){
					printf("%d ", result[i]);
				}
				break;
			case 'n':
				result = next_primes(strtol(argv[2], NULL, 10), strtol(argv[3], NULL, 10));
				for(int i = 0; i <= next_primes_size; i++){
					printf("%d ", result[i]);
				}
				break;
			default:
				printf("%s", optarg);
				break;
		}
	}
	return 0;
}
