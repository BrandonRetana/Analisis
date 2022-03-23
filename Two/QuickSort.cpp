#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j) {
	int oldNum = arr[i];
	arr[i] = arr[j];
	arr[j] = oldNum; 
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low-1);
	for (int j = low; j <= high-1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr, i, j);
		}		
	}
	swap(arr, i+1, high);
	return i+1;
}

int pivotSelection(int arr[], int low, int high) {
	int i = low;
	swap(arr, i, high);
	return partition(arr, low, high);
}

void quicksort(int arr[], int low, int high) {
	if (low < high) {
		int q = pivotSelection(arr, low, high);
		quicksort(arr, low, q-1);
		quicksort(arr, q+1,high);
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main() {
	int arr[] = {2,9,0,1,6};
	quicksort(arr, 0, 4);
	printArray(arr, 5);
}

