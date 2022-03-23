#include "dependencies.h"
using namespace std;

Trie *trie = new Trie();
TrieNode* root = trie->getNode();
QuickSort* qSort = new QuickSort();

int main() {
	setlocale(LC_ALL, "spanish");
	/*
	string text = "WarPeace.txt";
	trie->abrirArchivo(text, root);
	trie->searchLine(root, "Prince");
	*/
	
	int arr[6] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	qSort->sort(arr, n);


	return 0;
}