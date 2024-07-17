#include <iostream>
using namespace std;

class Queue {
 public:
  int queue[10000];
  int begin = 0;
  int end = 0;

  Queue() {}

  void push(int X) {
    queue[end] = X;
    end += 1;
  }

  bool empty() {
    if (end == begin) {
      return true;
    } else {
      return false;
    }
  }

  int pop() {
    if (empty()) {
      return -1;
    }
    int r = queue[begin];
    queue[begin] = 0;
    begin += 1;
    return r;
  }

  int size() { return end - begin; }

  int front() {
    if (empty()) {
      return -1;
    }
    return queue[begin];
  }

  int back() {
    if (empty()) {
      return -1;
    }
    return queue[end - 1];
  }
};

int main() {
  int N;
  cin >> N;

  Queue q;

  while (N--) {
    string cmd;
    cin >> cmd;

    if (cmd == "push") {
      int input;
      cin >> input;
      q.push(input);
    } else if (cmd == "pop") {
      cout << q.pop() << '\n';
    } else if (cmd == "size") {
      cout << q.size() << '\n';
    } else if (cmd == "empty") {
      cout << q.empty() << '\n';
    } else if (cmd == "front") {
      cout << q.front() << '\n';
    } else if (cmd == "back") {
      cout << q.back() << '\n';
    }
  }

  return 0;
}