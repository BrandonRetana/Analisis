#ifndef QUICKSORT_H
#define  QUICKSORT_H

class QuickSort
{
public:
void swap(int arr[], int i, int j);
int partition (int arr[], int low, int high);
void quicksort(int arr[], int low, int high, int pivot);
void printArray(int arr[], int size);
int pivotSelection(int arr[], int low, int high, int pivot);
QuickSort();
};

#endif // QUICKSORT_H