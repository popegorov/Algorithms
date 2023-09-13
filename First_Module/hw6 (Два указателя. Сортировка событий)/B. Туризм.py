n = int(input())
tops = [0] * n
pref_sum = [0] * n
for i in range(n):
    pref_sum[i] = [0, 0]
    x, y = map(int, input().split())
    tops[i] = y
for i in range(1, n):
    if tops[i] > tops[i - 1]:
        pref_sum[i][0] = pref_sum[i - 1][0] + tops[i] - tops[i - 1]
    else:
        pref_sum[i][0] = pref_sum[i - 1][0]
for i in range(n - 1):
    if tops[n - i - 1] < tops[n - i - 2]:
        pref_sum[n - i - 2][1] = pref_sum[n - i - 1][1]
        pref_sum[n - i - 2][1] += tops[n - i - 2] - tops[n - i - 1]
    else:
        pref_sum[n - i - 2][1] = pref_sum[n - i - 1][1]
k = int(input())
for i in range(k):
    s, f = map(int, input().split())
    if f > s:
        print(pref_sum[f - 1][0] - pref_sum[s - 1][0])
    else:
        print(pref_sum[f - 1][1] - pref_sum[s - 1][1])


