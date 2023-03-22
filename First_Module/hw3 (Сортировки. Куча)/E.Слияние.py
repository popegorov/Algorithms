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
n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
cnt1 = 0
cnt2 = 0
print(*sliyanie(a, b, cnt1, cnt2))


