#include <iostream>
using namespace std;

static int N;
static long dp[1001];
static long mod = 10007;

int main()
{
    cin >> N;

    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + (dp[i - 2] * 2)) % mod;
    }
    cout << dp[N] << "\n";

    return 0;
}