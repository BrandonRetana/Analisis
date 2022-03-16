#include <iostream>
#include <cmath>

using namespace std;

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
    int xFisrt = columns+M*rows;
    cout<<xFisrt<<endl<<yFirst<<endl;
return xFisrt > yFirst? yFirst: xFisrt;
}

int main() {
    int y[] = {3,4,6,0,1,1,1,1};
    int x[] = {7,5,1,6,0};
    cout<<costo(8, 5, x, y)<<endl;
return 0;
}
