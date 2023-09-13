n, m = map(int, input().split())
dp = [0] * n
for i in range(n):
    dp[i] = [0] * m
dp[0][0] = 1
for i in range(n):
    for j in range(m):
        if i == 0 or j == 0 or i == 1 and j == 1:
            pass
        elif i == 1:
            dp[i][j] = dp[i - 1][j - 2]
        elif j == 1:
            dp[i][j] = dp[i - 2][j - 1]
        else:
            dp[i][j] = dp[i - 1][j - 2] + dp[i - 2][j - 1]
print(dp[n - 1][m - 1])


