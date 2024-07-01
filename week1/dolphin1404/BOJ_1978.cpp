#include <iostream>

using namespace std;

bool isPrime[1001];

int main(){
  int N, num, cnt = 0;
  cin >> N;
  isPrime[1] = true;  // 소수가 아니면 true
  for (int i = 2; i < 1001; i++){
    for (int j = 2*i; j < 1001; j +=i){
      if(!isPrime[j]) isPrime[j] = true;
    }
  } // 에라토스테네스의 체

  for (int i = 0; i< N; i++){
    cin >> num;
    if(!isPrime[num]) cnt++;
  }
  cout << cnt;
}