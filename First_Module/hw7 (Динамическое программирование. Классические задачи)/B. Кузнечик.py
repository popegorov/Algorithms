n, k = map(int, input().split())
dp = [0] * n
dp[0] = 1
for i in range(1, min(k, n)):
    dp[i] = 2 ** (i - 1)
for i in range(k, n):
    for j in range(k):
        dp[i] += dp[i - j - 1]
print(dp[-1])


