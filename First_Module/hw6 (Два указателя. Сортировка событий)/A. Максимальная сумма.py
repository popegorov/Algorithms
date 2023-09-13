n = int(input())
a = list(map(int, input().split()))
pref_sum = [0] * n
pref_sum[0] = a[0]
cur_min = 0
max_sum = a[0]
for i in range(1, n):
    pref_sum[i] = a[i] + pref_sum[i - 1]
for i in range(n):
    if max_sum < pref_sum[i] - cur_min:
        max_sum = pref_sum[i] - cur_min
    if cur_min > pref_sum[i]:
        cur_min = pref_sum[i]
print(max_sum)


