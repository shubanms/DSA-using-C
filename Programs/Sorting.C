#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstring>

void selectionSort(int array[] , int n){

	for(int i=0;i<n-1;i++){
		int min = i;

		for(int j=i+1;j<n;j++){
			if(array[j] < array[min]){
				min = j;
			}

			if(min != i){
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void bubbleSort(int array[] , int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(array[j] > array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void insertionSort(int array[] , int n){
	int key;

	for(int i=1;i<n;i++){
		key = array[i];
		int j = i-1;

		while(j>=0 && array[j] > key){
			array[j+1] = array[j];
			j--;
		}

		array[j+1] = key;
	}
}

void countSort(int array[] , int n){
	int max = array[0];

	for(int i=0;i<n;i++){
		if(array[i] > max){
			max = array[i];
		}
	}

	int count[max+1] , answer[n];
	memset(count , 0 , sizeof(count));

	for(int i=0;i<n;i++){
		count[array[i]]++;
	}

	for(int i=1;i<max+1;i++){
		count[i] += count[i-1];
	}

	for(int i=0;i<n;i++){
		answer[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for(int i=0;i<n;i++){
		array[i] = answer[i];
	}
}

int main(){

	int array[10] = {9,8,7,6,5,4,3,2,1,0};
	int n = sizeof(array)/sizeof(array[0]);

	selectionSort(array , n);
	bubbleSort(array , n);
	insertionSort(array , n);
	countSort(array , n);

	for(int i=0;i<n;i++){
		printf("%d\n" , array[i]);
	}

	return 0;
}
