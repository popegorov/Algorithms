n, k, s = map(int, input().split())
min_sq = [0] * k**2
for i in range(s):
    min_sq[i] = 1
for i in range(n):
    for j in range(n):
        print(min_sq[(j * k + i) % (k ** 2)], end=' ')
    print('\n')


