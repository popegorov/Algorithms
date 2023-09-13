n, m = map(int, input().split())
p = 0
x = list(map(int, input().split()))
y = list(map(int, input().split()))
x_new = []
y_new = []
for i in range(n):
    x_new.append((x[i], i + 1))
for i in range(m):
    y_new.append((y[i], i + 1))
x_new = sorted(x_new)
y_new = sorted(y_new)
x = [0] * n
cnty = 0
cnt = 0
for cntx in range(n):
    while cnty != m and x_new[cntx][0] >= y_new[cnty][0]:
        cnty += 1
        cnt += 1
    if cnty == len(y_new):
        break
    if x_new[cntx][0] < y_new[cnty][0]:
        x[x_new[cntx][1] - 1] = y_new[cnty][1]
        cnty += 1
print(m - cnt)
print(*x)


