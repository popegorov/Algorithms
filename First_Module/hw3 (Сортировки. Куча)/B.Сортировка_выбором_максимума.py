def sort(a, start, end):
    index = a.index(max(a[start:end]))
    a[index], a[end - 1] = a[end - 1], a[index]
    return a
n = int(input())
nx = n
if n:
    a = list(map(int, input().split()))
while n != 0:
    a = sort(a, 0, n)
    n -= 1
if nx:
    print(*a)


