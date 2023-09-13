n = int(input())
dp = [0] * (n + 1)
dp[1] = 0
prev = [0] * (n + 1)
for i in range(2, n + 1):
    if i % 6 == 0:
        dp[i] = min(dp[i // 3], dp[i // 2], dp[i - 1]) + 1
        if min(dp[i // 3], dp[i // 2], dp[i - 1]) == dp[i // 3]:
            prev[i] = i // 3
        elif min(dp[i // 3], dp[i // 2], dp[i - 1]) == dp[i // 2]:
            prev[i] = i // 2
        else:
            prev[i] = i - 1
    elif i % 3 == 0:
        dp[i] = min(dp[i // 3], dp[i - 1]) + 1
        if min(dp[i // 3], dp[i - 1]) == dp[i // 3]:
            prev[i] = i // 3
        else:
            prev[i] = i - 1
    elif i % 2 == 0:
        dp[i] = min(dp[i // 2], dp[i - 1]) + 1
        if min(dp[i // 2], dp[i - 1]) == dp[i // 2]:
            prev[i] = i // 2
        else:
            prev[i] = i - 1
    else:
        dp[i] = dp[i - 1] + 1
        prev[i] = i - 1
print(dp[n])
opers = []
i = n
while i != 1:
    opers.append(i)
    i = prev[i]
opers.append(1)
print(*reversed(opers))


