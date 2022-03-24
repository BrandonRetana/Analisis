#include "Dependencies.h"
using namespace std;

void QuickSort::swap(int arr[], int i, int j) {
	int oldNum = arr[i];
	arr[i] = arr[j];
	arr[j] = oldNum; 
}

int QuickSort::partition(int arr[], int low, int high) {
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

int QuickSort::pivotSelection(int arr[], int low, int high, int pivot) {
	srand(time(NULL));
	int i = 0; 
	int random = low+rand()%(high - low);
	switch (pivot) {
	case 1:
		i = low;
	case 2:
		i = random;
	case 3:
		i = high;
	}
	swap(arr, i, high);
	return partition(arr, low, high);
}

void QuickSort::quicksort(int arr[], int low, int high, int pivot) {
	if (low < high) {
		int q = pivotSelection(arr, low, high, pivot);
		quicksort(arr, low, q-1, pivot);
		quicksort(arr, q+1,high, pivot);
	}
}

void QuickSort::printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

QuickSort::QuickSort() {

}
