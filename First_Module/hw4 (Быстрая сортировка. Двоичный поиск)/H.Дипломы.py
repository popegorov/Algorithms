a = input().split()
w = int(a[0])
h = int(a[1])
n = int(a[2])
l = 0
r = (w + h) * n
while l + 1 < r:
    m = (l + r) // 2
    if (m // w) * (m // h) >= n:
        r = m
    else:
        l = m
if (l // w) * (l // h) >= n:
    print(l)
else:
    print(r)


