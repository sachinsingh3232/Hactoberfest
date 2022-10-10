#include<stdio.h>
int linearSearch(int arr[], int size, int element){
	for(int i=0; i<size; i++){
		if(arr[i]==element){
			return i; 
		}
	}
	return -1;
}

int binarySearch(int arr[], int size, int element){
	int low , mid, high;
	low = 0;
	high = size-1;
	
	while(low<=high){
	mid = (high+low)/2;
	if(arr[mid]==element){
		return mid;
	}
	if(arr[mid]<element){
		low = mid + 1;
	}
	else{
		high = mid - 1;
	}
}
return -1;
}
int main(){
//	unsorted array for linearsearch
//	int arr[] = {1,3,5,56,4,87,98,336,9,78,12};
//	int size = sizeof(arr)/sizeof(int);
//	int element = 7;
//    int searchIndex = linearSearch(arr, size, element);

//    sorted array for linearsearch
    int arr[] = {1,3,5,7,9,87,98,336,789,1200};
	int size = sizeof(arr)/sizeof(int);
	int element = 120;
	int searchIndex = binarySearch(arr, size, element);
	printf("The element %d was found at index %d \n",element ,searchIndex);
	return 0;
}
