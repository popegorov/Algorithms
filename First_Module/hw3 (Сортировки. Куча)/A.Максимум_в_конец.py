def sort(a, start, end):
    index = a.index(max(a[start:end]))
    a[index], a[end - 1] = a[end - 1], a[index]
    return a
n = int(input())
a = list(map(int, input().split()))
if n:
    a = sort(a, 0, n)
print(*a)


