#include <stdio.h>
void func1(int num);
void func2(int num);
void func3(int num);


int main(){
	int choice = 0;
while(1){

	printf("Enter some int\n");
	scanf("%d", &choice);

	func1(choice);
	func2(choice);
	func3(choice);
}
return 0;
}

void func1(int num){
int i, j;
	for(i = 0; i < num; i++){
		for(j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
	printf("End of func1 \n\n");
}

void func2(int num){
int i, j;
	for(i = 0; i < num; i++){
		for(j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");

	}

	for(i = num-1; i > 0; i--){
		for(j = 0; j < i; j++){
			printf("*");
		}
		printf("\n");
	}
	printf("End of func2\n\n");

}

void func3(int num){
int i = 0, j = 0;

	int num_of_stars = 1;
	int mid = num;
for(j = 0; j < (num); j++){	
	for(i = 0; i< mid; i++)
		printf(" ");		
	for(i = 0; i< num_of_stars;i++)
		printf("*");
	num_of_stars += 2;
	mid -=1;
	printf("\n");
}
	printf("End of func3\n\n");

}


