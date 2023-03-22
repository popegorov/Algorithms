import random


def partition(a, x):
    cnt1 = -1
    cnt2 = len(a)
    for i in range(len(a)):
        if a[i] == x:
            if cnt1 == -1 and cnt2 == len(a):
                cnt1 = i
                cnt2 = i + 1
            elif cnt1 == -1:
                a[cnt2], a[i] = a[i], a[cnt2]
                cnt1 = cnt2
                cnt2 += 1
            else:
                a[cnt2], a[i] = a[i], a[cnt2]
                cnt2 += 1
        elif a[i] < x:
            if cnt1 != -1:
                j = a[cnt1]
                k = a[cnt2]
                a[cnt1] = a[i]
                a[cnt2] = j
                if cnt2 != i:
                    a[i] = k
                cnt1 += 1
                cnt2 += 1
            elif cnt2 != len(a):
                a[cnt2], a[i] = a[i], a[cnt2]
                cnt2 += 1
        else:
            if i < cnt2:
                cnt2 = i
    return (cnt1, cnt2)


def qsort(a, end):
    if len(a) <= 1:
        return a
    else:
        x = a[random.randint(0, end - 1)]
        b = partition(a, x)
        return (qsort(a[:b[0]], b[0]) + [x] * (b[1] - b[0]) +
                qsort(a[b[1]:], len(a) - b[1]))
n = int(input())
a = list(map(int, input().split()))
print(*qsort(a, len(a)))


