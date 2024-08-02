#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 2; i <= N;) {
    if (N % i == 0) {
      N /= i;
      cout << i << endl;
      continue;
    }
    i++;
  }
}