def sliyanie(a, b):
    cnt1 = 0
    cnt2 = 0
    c = []
    if type(a) == int:
        a = [a]
    if type(b) == int:
        b = [b]
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


def merge_sort(a):
    if len(a) <= 1:
        return a
    else:
        b = merge_sort(a[:len(a) // 2])
        c = merge_sort(a[len(a) // 2:])
        return sliyanie(b, c)

n = int(input())
a = list(map(int, input().split()))
print(*merge_sort(a))


