n = int(input())
a = list(map(int, input().split()))
for i in range(1, n):
    if a[i] < a[i - 1]:
        for j in range(i):
            if a[j] > a[i]:
                ai = a.pop(i)
                a = a[:j] + [ai] + a[j:]
                print(*a)
                break


