n = int(input())

dp = []
x = 1

for i in range(n):
    dp.append(list(map(int,input().split())))

for i in range(1,n):
    for j in range(x+1):
        if j == 0:
            dp[i][j] += dp[i-1][j]
        elif i == j:
            dp[i][j] += dp[i-1][j-1]
        else:
            dp[i][j] = max(dp[i][j] + dp[i-1][j-1],dp[i][j] + dp[i-1][j])
    x += 1


print(max(dp[n-1]))