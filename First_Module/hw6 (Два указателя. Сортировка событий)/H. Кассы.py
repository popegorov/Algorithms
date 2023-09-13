n = int(input())
day = [0] * 1440
cnt = 0
for i in range(n):
    h1, m1, h2, m2 = map(int, input().split())
    start = h1 * 60 + m1
    end = h2 * 60 + m2
    if start < end:
        for j in range(start, end):
            day[j] += 1
    elif start > end:
        for j in range(start, len(day)):
            day[j] += 1
        for j in range(end):
            day[j] += 1
    else:
        n -= 1
for i in day:
    if i == n:
        cnt += 1
print(cnt)


