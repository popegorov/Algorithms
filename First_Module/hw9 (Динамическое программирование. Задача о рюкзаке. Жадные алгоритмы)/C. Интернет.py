m = int(input())
a = list(map(int, input().split()))
a_cost = [0] * 30
pow2 = 1
pow_2 = []
for i in range(30):
    a_cost[i] = (a[i] / 2 ** i, i)
    pow_2.append(pow2)
    pow2 *= 2
a_cost.sort(reverse=True)
total_cost = 0
cur_total = pow2
cur_i = 0
while m > 0 and cur_i != 30:
    cur_total = min(cur_total, total_cost +
                    (m // a[a_cost[cur_i][1]] + 1) * pow_2[a_cost[cur_i][1]])
    total_cost += m // a[a_cost[cur_i][1]] * pow_2[a_cost[cur_i][1]]
    m -= m // a[a_cost[cur_i][1]] * a[a_cost[cur_i][1]]
    cur_i += 1
print(min(total_cost, cur_total))


