#include <iostream>

using namespace std;

static int N;
static long answer;
static long dp[1001];
static long arr[1001];


int main(){
  int count = 0;
  cin >> N;
  for (int i = 1; i <= N; i++){
    cin >> arr[i];
  }
  dp[1] = 1;
  int maxx = 1; //dp
  for (int i = 2; i <= N; i++){
    maxx = 1;
    for(int j = 1; j < i; j++){
      if(arr[j] < arr[i]){
        if(dp[j] + 1 > maxx){
          maxx = dp[j]+1;
        }
      }
    }
    dp[i] = maxx;
  }

  for (int i = 1; i <= N; i++){
    if(dp[i] > answer) answer = dp[i];
  }

  cout << answer;
}