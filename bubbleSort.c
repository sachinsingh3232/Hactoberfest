#include<stdio.h>

void printArray(int *arr, int size){
	for(int i = 0; i<size; i++){
		printf("%d ", arr[i]);
	}
}
void bubbleSort(int *arr, int n){
	int temp;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
void insertionSort(int *arr, int n){
	int key;
	for(int i=1; i<=n-1; i++){
		key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]<key){
			arr[j+1] = arr[j];
			j--;
		}
		
	}
}
int main(){
	int arr[] = { 12, 54, 65, 7, 23, 9};
	int size = 6;
	printArray(arr, size);
	printf("\n");
	bubbleSort(arr, size);
	printArray(arr, size);
	return 0;
}
