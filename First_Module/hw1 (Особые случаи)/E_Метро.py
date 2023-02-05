a = int(input())
b = int(input())
n = int(input())
m = int(input())
min1 = (n - 1) * (a + 1) + 1
max1 = n * (a + 1) + a
min2 = (m - 1) * (b + 1) + 1
max2 = m * (b + 1) + b
l = max(min1, min2)
h = min(max1, max2)
if l <= h:
    print(l, h)
else:
    print(-1)


