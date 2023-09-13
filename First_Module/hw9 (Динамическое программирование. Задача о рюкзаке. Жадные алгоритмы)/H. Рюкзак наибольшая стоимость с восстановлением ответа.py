n, m = map(int, input().split())
weights = list(map(int, input().split()))
costs = list(map(int, input().split()))
max_weight = [[-1] * (m + 1) for i in range(n + 1)]
max_weight[0][0] = 0
max_cnt = 0
for i in range(1, n + 1):
    for j in range(m + 1):
        if max_weight[i - 1][j] != -1:
            max_weight[i][j] = max_weight[i - 1][j]
        if weights[i - 1] <= j and max_weight[i - 1][j - weights[i - 1]] != -1:
            max_weight[i][j] = \
                max(max_weight[i - 1][j],
                    max_weight[i - 1][j - weights[i - 1]] + costs[i - 1])
cur_val = max(max_weight[-1])
cur_j = max_weight[-1].index(cur_val)
cur_i = n
ruc = []
while cur_j != 0:
    if max_weight[cur_i - 1][cur_j] == max_weight[cur_i][cur_j]:
        cur_i -= 1
    else:
        ruc.append(cur_i)
        cur_i -= 1
        cur_j -= weights[cur_i]
ruc = ruc[::-1]
for elem in ruc:
    print(elem)


