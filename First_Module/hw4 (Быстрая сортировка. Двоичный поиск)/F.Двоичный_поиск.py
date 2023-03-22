a = input().split()
n = int(a[0])
k = int(a[1])
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for i in range(k):
    x = b[i]
    l = 0
    r = n - 1
    flag = False
    while l + 1 != r:
        m = (r + l) // 2
        if x < a[m]:
            r = m
        elif x == a[m]:
            flag = True
            break
        else:
            l = m
    if flag:
        print('YES')
    elif a[l] == x or a[r] == x:
        print('YES')
    else:
        print('NO')


