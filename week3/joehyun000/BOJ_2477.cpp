#include <iostream>
#include <cmath>
using namespace std;

void star(int i, int j, int N) {
    if(N == 3) {
        if(i %3 ==1 && j%3 == 1) {
            cout << " ";
        }   
        else {
            cout << "*";
        }
    }
 
     
}

int main() {
    int k;
    cin >> k;

    int N = pow(3,k);

    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star(i, j, N);
		}
		cout << '\n';
	}
}