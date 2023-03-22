def merge(start, end, x):
    global a
    while start < end:
        if a[start] >= x and a[end] < x:
            a[start], a[end] = a[end], a[start]
            start += 1
            end -= 1
        elif a[start] >= x:
            end -= 1
        elif a[end] < x:
            start += 1
        else:
            end -= 1
            start += 1
    if a[end] < x:
        print(len(a[:end]) + 1)
        print(len(a[end:]) - 1)
    else:
        print(len(a[:end]))
        print(len(a[end:]))

n = int(input())
a = list(map(int, input().split()))
x = int(input())
if n:
    merge(0, n - 1, x)
else:
    print(0)
    print(0)


