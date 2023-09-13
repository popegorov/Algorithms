n, m = map(int, input().split())
a = list(map(int, input().split()))
max_weight = [0] * (m + 1)
max_weight[0] = 1
maxcnt = 0
for i in range(n):
    for j in range(m + 1 - a[i]):
        if max_weight[m - j - a[i]] == 1:
            max_weight[m - j] = 1
            if m + 1 - j > maxcnt:
                maxcnt = m - j
print(maxcnt)


