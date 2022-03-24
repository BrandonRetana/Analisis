#include "Dependencies.h"
using namespace std;

Trie *trie = new Trie();
TrieNode* root = trie->getNode();
QuickSort* qSort = new QuickSort();
InsertionSort* iSort = new InsertionSort();

int main() {
	setlocale(LC_ALL, "spanish");
	int arr[] = {1, 99, 5, 7, 4, 6, 2, 55};
	int arr2[] = {1, 99, 5, 7, 4, 6, 2, 55};
	qSort->quicksort(arr, 0, 7, 3);
	iSort->insertionSort(arr2, 8);
	qSort->printArray(arr, 8);
	qSort->printArray(arr2, 8);
	return 0;
}