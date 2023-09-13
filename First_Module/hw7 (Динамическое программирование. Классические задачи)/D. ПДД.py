n, m = map(int, input().split())
dp = [0] * n
for i in range(n):
    dp[i] = list(map(int, input().split()))
prev = [0] * n
for i in range(n):
    prev[i] = [0] * m
for i in range(n):
    for j in range(m):
        if i == 0 and j == 0:
            pass
        elif i == 0:
            dp[i][j] += dp[i][j - 1]
            prev[i][j] = 0
        elif j == 0:
            dp[i][j] += dp[i - 1][j]
            prev[i][j] = 1
        else:
            dp[i][j] += min(dp[i][j - 1], dp[i - 1][j])
            if dp[i][j - 1] < dp[i - 1][j]:
                prev[i][j] = 0
            else:
                prev[i][j] = 1
print(dp[-1][-1])
print(n + m - 1)
pers = []
curi = n - 1
curj = m - 1
while curi != 0 or curj != 0:
    pers.append((curi, curj))
    if prev[curi][curj] == 0:
        curj -= 1
    else:
        curi -= 1
print(1, 1)
for elem in pers[::-1]:
    print(elem[0] + 1, elem[1] + 1)


