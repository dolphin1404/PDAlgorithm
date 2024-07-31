#include <iostream>

using namespace std;

static int N;

static long dp[91][2];

int main(){
  cin >> N;

  dp[1][1] = 1; // dp[0][0]
  dp[1][0] = 0; // dp[0][1] + dp[0][0]

  for(int i = 2; i <= N; i++){
    dp[i][0] = dp[i-1][1] + dp[i-1][0];
    dp[i][1] = dp[i-1][0];
  }
  
  cout << dp[N][0] + dp[N][1];
}