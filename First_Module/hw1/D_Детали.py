a = list(map(int, input().split()))
n = a[0]
k = a[1]
m = a[2]
cnt = 0
l = k // m
r = k % m
if m <= k:
    while n >= k:
        w = n // k
        cnt += w * l
        n = w * r + n % k
print(cnt)


