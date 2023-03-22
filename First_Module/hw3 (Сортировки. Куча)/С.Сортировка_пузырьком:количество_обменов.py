n = int(input())
a = list(map(int, input().split()))
cnt = 0
for i in range(n):
    for j in range(1, n):
        if a[j - 1] > a[j]:
            a[j], a[j - 1] = a[j - 1], a[j]
            cnt += 1
print(cnt)




