#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a, int b){
  int tmp;
  while(b > 0){
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}

int main(){
  int N, S, D;

  cin >> N >> S;
  int *arr = new int[N];

  for(int i = 0; i < N; i++){
    cin >> arr[i];
    arr[i] = abs(S - arr[i]);
  }

  D = arr[0];

  for(int i = 1; i < N; i++){
    D = GCD(D, arr[i]);
  }
  cout << D << "\n";
}