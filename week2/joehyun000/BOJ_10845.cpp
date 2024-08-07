#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    int N;		
    string command;	
    int num;	

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> command; 
        
        if(command == "push") {  // push X: 정수 X를 큐에 넣는 연산이다.
            cin >> num;
            q.push(num);
        }

        else if(command == "pop") {    // pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
            if(q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        }

        else if(command == "size") {    // size: 큐에 들어있는 정수의 개수를 출력한다.
            cout << q.size() << endl;
        }

        else if(command == "empty") {  // empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
            if(q.empty()) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }

        else if(command == "front") {   // front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
            if(q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.front() << endl;
            }
        }

        else if(command == "back") {    // back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
            if(q.empty()) {
                cout << -1 << endl;
            } else {
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}
