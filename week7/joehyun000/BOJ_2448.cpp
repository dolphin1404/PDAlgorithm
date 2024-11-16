#include <iostream>
#include <algorithm>
using namespace std;

char arr[10000][10000];

void firstDraw(int sx, int sy) {
    arr[sx][sy] = '*';
    arr[sx+1][sy-1] = '*';
    arr[sx+1][sy+1] = '*';
    for(int i = sy-2; i <= sy + 2; i++) {
        arr[sx+2][i] = '*';
    } 
}

void Draw(int sx, int sy, int len) {
    if(len == 3) {
        firstDraw(sx,sy);
        return ;
    }
    else if(len < 3) return;

    else{
        len /= 2;
        int halfX = len; 
        int halfY = len; 

        Draw(sx, sy, len);                 
        Draw(sx + halfX, sy - halfY, len); 
        Draw(sx + halfX, sy + halfY, len); 
    }
}

int main() {
    int N;
    cin >> N;

    fill(&arr[0][0],&arr[9999][10000],' ');

    int sy = (2*N-1)/2;

    Draw(0,sy,N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2*N-1; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}
