#include <iostream>
#include <cmath>
#include<list>

using namespace std;

//--------------------------------------------------------------Costo--------------------------------------------------------------
/* 
Funcion:
f(n) = 6n+6k+12

O grande:
O(n+k)

Loop invariant:
En la linea 24 y 27
Las condiciones del loop invariant son:
rows <= que la sumatoria desde i = 0 hasta N-1 de y[i]
columns <= que la sumatoria desde i = 0 hasta M-1 de x[i]
*/
int costo(int N, int M, int x[], int y[]){
    int columns = 0;
    int rows = 0;
    for (int i = 0; i < N; i++) {
        rows+= y[i];
    }
    for (int j = 0; j < M; j++) {
        columns+= x[j];
    }
    int yFirst = rows+N*columns;
    int xFirst = columns+M*rows;
return xFirst > yFirst? yFirst: xFirst;
}
//--------------------------------------------------------------RadixSort--------------------------------------------------------------
/* 
Funcion:
f(n) = 47m+33mn+9

O grande:
O(nk)

Loop invariant:
En la linea 62
Las condiciones del loop invariant son:
count <= N
*/
void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];      //radix of decimal number is 10
   for(i = 0; i< max; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;      //find index for pocket array
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}

void printArr(int* arr, int n) {
   for (int i = 0; i < n; i++) {
      cout<<arr[i]<<" ";
   }
   cout<<endl;
}

int main() {
    int y[] = {3,4,6,0};
    int x[] = {7,5,1,6,0};
    cout<<"Costo:\n"<<"x = 7,5,1,6,0\n"<<"y = 3,4,6,0\n"<<"Salida: "<<endl;
    cout<<costo(4, 5, x, y)<<endl;
    
    cout<<"RadixSort:\n"<<"arr = 201,10,132,55,7 \n"<<"Salida:"<<endl;
    int* arr = new int[5];
    arr[0] = 201;
    arr[1] = 10;
    arr[2] = 132;
    arr[3] = 55;
    arr[4] = 7;
   printArr(arr,5);
   radixSort(arr,5,3);
   printArr(arr,5);
return 0;
}

//Si quiere ver con mas claridad la informacion extraida de los algoritmos puede ver PDF adjunto en esta misma carpeta. 