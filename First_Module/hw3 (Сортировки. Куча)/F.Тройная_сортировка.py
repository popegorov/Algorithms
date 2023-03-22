def sliyanie(a, b, cnt1, cnt2):
    c = []
    while cnt1 < len(a) and cnt2 < len(b):
        if a[cnt1] <= b[cnt2]:
            c.append(a[cnt1])
            cnt1 += 1
        else:
            c.append(b[cnt2])
            cnt2 += 1
    if len(a) - cnt1 == 0:
        c += b[cnt2:]
    else:
        c += a[cnt1:]
    return c
n = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
cnt1 = 0
cnt2 = 0
first = sliyanie(a, b, cnt1, cnt2)
second = sliyanie(first, c, cnt1, cnt2)
print(*second)


