#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N,K;
    queue<int> q;
    vector<int> arr;
    cin >> N >> K;

    for(int i = 1 ; i<= N; i++) {
        q.push(i);
    }
    while(!q.empty()) {
        for(int i = 1; i < K ; i++) {
            q.push(q.front());
            q.pop();
        }
        arr.push_back(q.front());
        q.pop();
    }
    cout << "<";
    for(int i=0; i<arr.size();i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << arr[i];
    }
    cout << ">";
    return 0;
}