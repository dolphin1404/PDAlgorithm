#include <iostream>
#include <vector>
using namespace std;

int arr[2187][2187];
int answer[3];

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

void solve(int x, int y, int N) {
    if(!isSame(x,y,N)) {
        int len = N/3;

        for (int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                solve(len*j+x, len*i+y, len);
            }
        }
    }
    else {
        int paperNum = arr[y][x];
        answer[paperNum + 1]++;
        return;
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

    for (int i = 0; i < 3; i++) {
        cout << answer[i] << "\n";
    }
 
    return 0;
}