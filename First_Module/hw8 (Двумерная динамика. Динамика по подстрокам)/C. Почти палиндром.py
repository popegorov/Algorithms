n, k = map(int, input().split())
word = input()
dp0 = [0] * n
dp1 = [0] * n
cnt = n
for length in range(2, n + 1):
    dp_cur = [0] * n
    for left in range(n - length + 1):
        if word[left] == word[left + length - 1]:
            dp_cur[left] = dp0[left + 1]
        else:
            dp_cur[left] = dp0[left + 1] + 1
        if dp_cur[left] <= k:
            cnt += 1
    dp0 = dp1
    dp1 = dp_cur
print(cnt)


