n = int(input())
a = list(map(int, input().split()))
b = [-1] * 10**6
for i in range(n):
    if b[a[i]] == -1:
        b[a[i]] = i
    else:
        a[b[a[i]]] = -1
        b[a[i]] = i
b = []
for i in range(n):
    if a[i] != -1:
        b.append(a[i])
print(len(b))
print(*b)


