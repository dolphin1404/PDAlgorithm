#include <iostream>

using namespace std;

bool isit(int x) {
  if (x < 2) return false;
  for (int i = 2; i < x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  int T, n;
  int a, b;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n;
    a = n / 2;
    b = n / 2;
    while (1) {
      if (isit(a) && isit(b)) {
        cout << a << " " << b << endl;
        break;
      }
      a--;
      b++;
    }
  }
}