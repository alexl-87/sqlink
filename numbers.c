#include <stdio.h>
#include <math.h> 

int polindrome(int number);
int reverse(int number);
int ascendingOrder(int number);
int perfectNumber(int number);
int primeNumber(int number);

int main(){

	int number = 0, choise =0, result = -1;
	while(1){
	result = -1; choise =0;
	printf("chose a number\n");
	scanf("%d", &number);
	printf("Which function do you want to use?\n1-Palindrome, 2 - Reverse number, 3 - Ascending order, 4 - Perfect number, 5 - Prime number\n");
	scanf("%d", &choise);
	switch(choise){
		
		case 1: 
		result = polindrome(number);
		if (result == 1)
			printf("the number is polindrome\n");
		else if (result == 0)
			printf("the number is not polindrome\n");
		else
			printf("some error occured\n");
		break;

		case 2: 
		printf("%d\n", reverse(number));	
		break;
	
		case 3: 
		result = ascendingOrder(number);
		if (result == 1)
			printf("the number is in ascending order\n");
		else if (result == 0)
			printf("the number is not in ascending order\n");
		else
			printf("some error occured\n");
		break;

		case 4:
		result = perfectNumber(number); 
		if (result == 1)
			printf("the number is perfect\n");
		else if (result == 0)
			printf("the number is not perfect\n");
		else
			printf("some error occured\n");
		break;


		case 5:
		result = primeNumber(number);
		if (result == 1)
			printf("the number is prime\n");
		else if (result == 0)
			printf("the number is not prime\n");
		else
			printf("some error occured\n");
		break;
	}
}	
	return 0;
}

int polindrome(int number){
	int result = 0;
	int compare = reverse(number);

	if(compare == number)
		result = 1;

	return result;
	
}

int reverse(int number){
	
	int result = 0;

	while(number > 0){
		result = (result*10)+(number%10);
		number /= 10;
	}
	return result;
}

int perfectNumber(int number){
	int devider = 2, sum = 1, mul = 1, result = 0;
	
	while (devider < sqrt(number)+1){
		
		if(number%devider == 0){
			sum+=devider;
			mul *= devider;
		}
		devider++;
	}
	if (sum == mul)
		result = 1;
	
	return result;

}
int ascendingOrder(int number){
	int result = 1, x = 0, y = 0;
	
	while(number/10 > 0){
		x = number%10;
		y = (number/10)%10;
		if(x < y){
			result = 0;
			break;
		}
		else
			number /= 10;
			
	}
	return result;	
}
int primeNumber(int number){
	int devider = sqrt(number)+1, result = 1, i = 0;
	for(i = 2; i < devider; i++){
		if(number%i == 0){
		result = 0;
		break;
		}
	}
	
	return result;
}


