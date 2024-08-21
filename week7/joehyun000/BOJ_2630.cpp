#include <iostream>
#include <vector>
using namespace std;

int arr[128][128];
int white = 0;
int blue = 0;

bool isSame(int x, int y, int N) {
    int num = arr[y][x];
    for (int i = y; i < y + N; i++) {
        for (int j = x; j < x + N; j++) {
            if (arr[i][j] != num) {
                return false;
            }
        }
    }
    return true;
}


void solve(int y, int x, int N) {
    if(!isSame(x,y,N)) {
        int len = N/2;

        for (int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                solve(len*j+y, len*i+x, len);
            }
        }
    }
    else {
        if(arr[y][x] == 0) {
            white++;
        }
        else {
            blue++;
        }
    }
}

int main() {
    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    solve(0,0,N);

    cout << white << "\n" << blue;
}