n, m = map(int, input().split())
dp = [[0] * m for i in range(n)]
dp[0] = [1] * m
for i in range(1, n):
    dp[i][0] = 1
    for j in range(1, m):
        dp[i][j] = dp[i - 1][j]
        for k in range(1, j + 1):
            dp[i][j] += 2 * dp[i - 1][j - k]
print(dp[n - 1][m - 1])


