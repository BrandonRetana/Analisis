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
	

int main() {
	int n = 1;
	int arr[15000];
	unsigned t0,t1 = 0;
	double oldTime, oldTeoric;
	setlocale(LC_ALL, "spanish");
	cout<<"Con pivote fijo en la primera posicion\ncrecimiento teorico de n*log(n)"<<endl;
	
	while (n <= 10) {
		randomArr((n*100), arr, (n*100));
		t0 = clock();
		qSort->quicksort(arr,0,(n*100-1),3);
		t1 = clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		double teoric = n*100 *log2(n*100);
		cout<<"Time: "<<time/oldTime<<"\nTeoric: "<<teoric/oldTeoric<<endl<<endl;
		oldTime = time;
		oldTeoric = teoric;
		n++;
	}
	
	

return 0;
}