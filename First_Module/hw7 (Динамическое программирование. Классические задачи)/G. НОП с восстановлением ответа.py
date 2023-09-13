n = int(input())
a = input().split()
m = int(input())
b = input().split()
dp = [0] * (n + 1)
ans = []
for i in range(n + 1):
    dp[i] = [0] * (m + 1)
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if a[i - 1] == b[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
curi = n
curj = m
while curi != 0 and curj != 0:
    if dp[curi][curj] == dp[curi][curj - 1]:
        curj -= 1
    elif dp[curi][curj] == dp[curi - 1][curj]:
        curi -= 1
    else:
        ans.append(a[curi - 1])
        curi -= 1
        curj -= 1
print(*reversed(ans))


