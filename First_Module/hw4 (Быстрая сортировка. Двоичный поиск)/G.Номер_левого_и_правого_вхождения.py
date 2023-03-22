n = int(input())
a = list(map(int, input().split()))
k = int(input())
b = list(map(int, input().split()))
for i in range(k):
    x = b[i]
    l = 0
    r = n - 1
    while l + 1 != r:
        m = (r + l) // 2
        if x > a[m]:
            l = m
        else:
            r = m
    if a[l] == x:
        print(l + 1, end=' ')
    elif a[r] == x:
        print(r + 1, end=' ')
    else:
        print(0, end=' ')
    l = 0
    r = n - 1
    while l + 1 != r:
        m = (r + l) // 2
        if x < a[m]:
            r = m
        else:
            l = m
    if a[r] == x:
        print(r + 1)
    elif a[l] == x:
        print(l + 1)
    else:
        print(0)


