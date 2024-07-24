#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

struct numCompare {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main() {
    int N;
    cin >> N;
    priority_queue<int, vector<int>, numCompare> q;

    for (int i = 0; i < N; ++i) {
        int command;
        cin >> command;

        if (command == 0) {
            if (q.empty()) {
                cout << "0" << endl;
            } else {
                cout << q.top() << endl;
                q.pop();
            }
        } else {
            q.push(command);
        }
    }

    return 0;
}
