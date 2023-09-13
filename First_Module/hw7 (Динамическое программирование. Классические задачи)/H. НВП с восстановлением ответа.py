n = int(input())
a = list(map(int, input().split()))
dp = [0] * n
prev = []
for i in range(n):
    max_cnt = 0
    max_j = -1
    for j in range(0, i):
        if a[j] < a[i] and dp[j] > max_cnt:
            max_cnt = dp[j]
            max_j = j
    dp[i] = max_cnt + 1
    prev.append(max_j)
curi = dp.index(max(dp))
ans = []
while curi != -1:
    ans.append(a[curi])
    curi = prev[curi]
print(*reversed(ans))


