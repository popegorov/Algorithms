n = int(input())
dp = [2, 4, 7, 13]
for i in range(4, n):
    new_dp = 2 * dp[i - 1] - dp[i - 4]
    dp.append(new_dp)
print(dp[n - 1])


