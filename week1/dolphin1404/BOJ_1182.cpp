#include <iostream>

using namespace std;

int N, S, answer = 0;
int *arr;

void func(int n, int s){
  if(n == N){
    if(s == S) answer++;
    return;
  }
  func(n+1, s);
  func(n+1, s+ arr[n]);
}

int main(){
  cin >> N >> S;
  arr = new int[N];
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
  func(0,0);
  if(S == 0) answer--;
  cout << answer;
}