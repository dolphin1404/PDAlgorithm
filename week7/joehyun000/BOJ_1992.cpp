#include <iostream>
using namespace std;

int arr[64][64];

void printResult(int y, int x, int size) {
    int now = arr[y][x];

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if(arr[i][j] != now) {
                cout << "(";
                printResult(y, x, size/2);
                printResult(y, x+size/2, size/2);
                printResult(y + size / 2, x, size/2);
                printResult(y + size / 2,x + size / 2, size/2);
                cout << ")";
                return;
            }
            
        }
        
    }
    cout << now;  
}

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < N; j++) {
            arr[i][j] = line[j] - '0'; 
        }
    }

    printResult(0,0,N);
    cout << endl;
    return 0;    
}