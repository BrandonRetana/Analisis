#ifndef QUICKSORT_H
#define  QUICKSORT_H

class QuickSort
{
public:
void swap(int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);
void sort(int arr[], int n);
QuickSort();
};

#endif // QUICKSORT_H