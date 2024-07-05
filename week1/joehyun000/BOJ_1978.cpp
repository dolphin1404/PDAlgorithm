#include <iostream>
using namespace std;

int main() {
    int n;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num <= 1) {
            continue;
        }
        else if (num == 2) {
            count++;
        }
        else {
            bool isPrime = true;
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
