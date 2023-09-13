n, r = map(int, input().split())
d = [int(_) for _ in input().split()]
right = 0
cnt = 0
for left in range(n):
    while right < len(d) and d[right] <= d[left] + r:
        right += 1
    if right < len(d) and d[right] > d[left] + r:
        cnt += n - right
print(cnt)


