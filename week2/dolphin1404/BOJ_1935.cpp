#include <iostream>
#include <stack>
using namespace std;
stack<double> s;
string str;
int arr[26];
int N;
double cal(char c) {
  double op1, op2;
  op2 = s.top();
  s.pop();
  op1 = s.top();
  s.pop();
  switch (c) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
  }
}
int main(void) {
  cout << fixed;
  cout.precision(2);

  cin >> N >> str;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    arr[i] = num;
  }
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      s.push(arr[str[i] - 'A']);
    else
      s.push(cal(str[i]));
  }
  cout << s.top();
}