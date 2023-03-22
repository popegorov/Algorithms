a1 = list(map(int, input().split()))
a2 = list(map(int, input().split()))
cnt = 0
while len(a1) != 0 and len(a2) != 0 and cnt < 10 ** 6:
    if a1[0] == 0 and a2[0] == 9:
        a1.append(a1[0])
        a1.append(a2[0])
        a1.pop(0)
        a2.pop(0)
    elif a1[0] == 9 and a2[0] == 0:
        a2.append(a1[0])
        a2.append(a2[0])
        a1.pop(0)
        a2.pop(0)
    elif a1[0] > a2[0]:
        a1.append(a1[0])
        a1.append(a2[0])
        a1.pop(0)
        a2.pop(0)
    else:
        a2.append(a1[0])
        a2.append(a2[0])
        a1.pop(0)
        a2.pop(0)
    cnt += 1
if len(a2) == 0:
    print('first', cnt)
elif len(a1) == 0:
    print('second', cnt)
else:
    print('botva')


