#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

int arr[100] , data , top = -1 , choice , check = true;

void push(int arr[] , int data){
	if(top == 100-1){
		printf("OVER-FLOW\n");
	}
	else{
		top++;
		arr[top] = data; 
	}
}

void pop(int arr[] , int data){
	if(top == -1){
		printf("UNDER-FLOW\n");
	}
	else{
		top--;
	}
}

void printArray(int arr[]){
	if(top == -1){
		printf("STACK IS EMPTY\n");
	}
	else{
		for(int i=top ; i>=0 ; i--){
			printf("%d\n" , arr[i]);
		}
	}
}

int main(){


	printf("1. POP\n");
	printf("2. PUSH\n");
	printf("3. PRINT\n");
	printf("4. EXIT\n");
	printf("\n");

	while(check){
		printf("Enter the choice\n");
		scanf("%d" , &choice);

		printf("\n");

		switch(choice){
			case 1:
				pop(arr , data);
				break;
			case 2:
				printf("Enter the data\n");
				scanf("%d" , &data);

				push(arr , data);

				printf("\n");
				break;
			case 3:
				printArray(arr);
				break;
			case 4:
				check = false;
				break;
			default:
				check = false;
				break;
		}
	}

	return 0;
}
