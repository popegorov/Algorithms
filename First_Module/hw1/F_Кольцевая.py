a = list(map(int, input().split()))
n = a[0]
i = a[1]
j = a[2]
first = abs(j - i) - 1
second = n - max(i, j) + min(i, j) - 1
print(min(first, second))


