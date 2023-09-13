n, m = map(int, input().split())
weights = list(map(int, input().split()))
costs = list(map(int, input().split()))
max_weight = [-1] * (m + 1)
max_weight[0] = 0
maxcnt = 0
for i in range(n):
    for j in range(m + 1 - weights[i]):
        if max_weight[m - j - weights[i]] != -1:
            max_weight[m - j] = max(max_weight[m - j],
                                    max_weight[m - j - weights[i]] + costs[i])
            if max_weight[m - j] > maxcnt:
                maxcnt = max_weight[m - j]
print(maxcnt)


