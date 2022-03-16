#include <iostream>

using namespace std;

int costo(int N, int M, int x[], int y[]){
    int vertical = 0;
    int horizontal = 0;
    for (int i = 0; i < N; i++) {
        horizontal+= y[i];
    }
    for (int j = 0; j < M; j++) {
        vertical+= x[j];
    }
    int yFirst = horizontal+N*vertical;
    int xFisrt = vertical+M*horizontal;

    cout<<xFisrt<<endl<<yFirst<<endl;
return 0;
}

int main() {
    int x[] = {7,5,1,6,0};
    int y[] = {3,4,6,0};
    costo(4, 5, x, y);
return 0;
}
