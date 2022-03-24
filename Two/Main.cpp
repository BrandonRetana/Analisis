#include "Dependencies.h"
using namespace std;

Trie *trie = new Trie();
TrieNode* root = trie->getNode();
QuickSort* qSort = new QuickSort();
InsertionSort* iSort = new InsertionSort();
unsigned t0,t1;

void randomArr(int n, int arr[], int max) {
	srand( time( 0 ) );
	for (int i = 0; i < n; ++i )
    	arr[ i ] = rand() % max;
}

void linealArr(int n, int arr[], int max) {
	for (int i = 0; i < n; ++i )
    	arr[ i ] = i;
}

void linealArrDecen(int n, int arr[], int max) {
	for (int i = n; i >= 0; i--)
    	arr[ i ] = i;
}
	

int main() {
	int n = 1;
	int arr[15000];
	unsigned t0,t1 = 0;
	double oldTime, oldTeoric;
	setlocale(LC_ALL, "spanish");
	cout<<"Quicksort 10 pruebas con pivote fijo en la primera posicion, 10 con pivote random, 10 con pivote fijo en la ultima posicion con arreglo random\ncrecimiento teorico de n*log(n)"<<endl;

	for(int i = 1; i <= 3; i++){
		cout<<"10 pruebas\n"<<endl;
		n = 1;
	while (n <= 10) {
		randomArr((n*1000), arr, (n*1000));
		t0 = clock();
		qSort->quicksort(arr,0,(n*1000-1),i);
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		double teoric = n*1000 *log2(n*1000);
		cout<<"Time: "<<time<<"\nGrowth rate: "<<time/oldTime<<"\nTeoric growth rate: "<<teoric/oldTeoric<<endl<<endl;
		oldTime = time;
		oldTeoric = teoric;
		n++;
		}
	}

	cout<<"\n10 pruebas con pivote fijo en la ultima posicion con arreglo ordenado\ncrecimiento teorico n^2\n"<<endl;
	n = 1;
	while (n <= 10) {
		linealArr((n*1000), arr, (n*1000));
		t0 = clock();
		qSort->quicksort(arr,0,(n*1000-1),3);
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		double teoric = n*1000 * n*1000;
		cout<<"Time: "<<time<<"\nGrowth rate: "<<time/oldTime<<"\nTeoric growth rate: "<<teoric/oldTeoric<<endl<<endl;
		oldTime = time;
		oldTeoric = teoric;
		n++;
		}

		cout<<"Pruebas del freetext, se realizaran 4 pruebas con diferentes sizes del patron de las letras, deido a que esta construido con un arbol Trie, su taza de crecimiento es de O(n) siendo el n el size del patron de letras"<<endl;
		trie->abrirArchivo("WarPeaceM.txt", root);

		t0 = clock();
		trie->searchLine(root, "Prince");
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		double teoric = 23;
		cout<<"Time: "<<time<<"\nGrowth rate: "<<time/oldTime<<"\nTeoric growth rate: "<<teoric/oldTeoric<<endl<<endl;
		oldTime = time;
		oldTeoric = teoric;

		t0 = clock();
		trie->searchLine(root, "floccinaucinihilipilification");
		t1 = clock();
		time = (double(t1-t0)/CLOCKS_PER_SEC);
		teoric = 29;
		cout<<"Time: "<<time<<"\nGrowth rate: "<<time/oldTime<<"\nTeoric growth rate: "<<teoric/oldTeoric<<endl<<endl;
		oldTime = time;
		oldTeoric = teoric;


		t0 = clock();
		trie->searchLine(root, "pseudopseudohypoparathyroidism");
		t1 = clock();
		time = (double(t1-t0)/CLOCKS_PER_SEC);
		teoric = 30;
		cout<<"Time: "<<time<<"\nGrowth rate: "<<time/oldTime<<"\nTeoric growth rate: "<<teoric/oldTeoric<<endl<<endl;
		oldTime = time;
		oldTeoric = teoric;

		t0 = clock();
		trie->searchLine(root, "pneumonoultramicroscopicsilicovolcanoconiosis");
		t1 = clock();
		time = (double(t1-t0)/CLOCKS_PER_SEC);
		teoric = 45;
		cout<<"Time: "<<time<<"\nGrowth rate: "<<time/oldTime<<"\nTeoric growth rate: "<<teoric/oldTeoric<<endl<<endl;
		oldTime = time;
		oldTeoric = teoric;



		cout<<"10 pruebas del insertion sort tiene un crecimiento teorico O(n)"<<endl<<endl;
		n = 1;
		while (n <= 10) {
		linealArr((n*1000), arr, (n*1000));
		t0 = clock();
		iSort->insertionSort(arr, n*1000);
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		double teoric = n*1000;
		cout<<"Time: "<<time<<"\nGrowth rate: "<<time/oldTime<<"\nTeoric growth rate: "<<teoric/oldTeoric<<endl<<endl;
		oldTime = time;
		oldTeoric = teoric;
		n++;
		}

		cout<<"10 pruebas del insertion sort tiene un crecimiento teorico O(n^2)"<<endl<<endl;
		n = 1;
		while (n <= 10) {
		linealArrDecen((n*1000), arr, (n*1000));
		t0 = clock();
		iSort->insertionSort(arr, n*1000);
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		double teoric = n*1000 * n*1000;
		cout<<"Time: "<<time<<"\nGrowth rate: "<<time/oldTime<<"\nTeoric growth rate: "<<teoric/oldTeoric<<endl<<endl;
		oldTime = time;
		oldTeoric = teoric;
		n++;
		}

		
		


return 0;
}