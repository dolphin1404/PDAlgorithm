#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, mind;
    vector<string> appear(100);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> appear[i];
    }

    cin >> mind;

    switch (mind) {
        case 1:
            for (int i = 0; i < N; i++) {
                cout << appear[i] << endl;
            }
            break;  

        case 2:
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < appear[i].length(); j++) {
                    cout << appear[i][appear[i].length() - j - 1];
                }
                cout << endl;
            }
            break;  

        case 3:
            for (int i = 0; i < N; i++) {
                cout << appear[N - i - 1] << endl;
            }
            break;  
    }
    return 0;
}
