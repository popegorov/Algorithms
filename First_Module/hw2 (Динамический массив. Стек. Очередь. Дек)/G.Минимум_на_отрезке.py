from collections import deque
a = input().split()
n = int(a[0])
k = int(a[1])
a = list(map(int, input().split()))
b = deque()
for i in range(k):
    while len(b) != 0 and a[i] <= b[-1][0]:
        b.pop()
    b.append((a[i], i))
for i in range(k, n):
    print(b[0][0])
    if b[0][1] + k == i:
        b.popleft()
    while len(b) != 0 and a[i] <= b[-1][0]:
        b.pop()
    b.append((a[i], i))
print(b[0][0])


