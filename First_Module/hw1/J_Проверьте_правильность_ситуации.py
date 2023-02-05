a1 = input().split()
a2 = input().split()
a3 = input().split()
b1 = a1[0] + a2[0] + a3[0]
b2 = a1[1] + a2[1] + a3[1]
b3 = a1[2] + a2[2] + a3[2]
c1 = a1[0] + a2[1] + a3[2]
c2 = a1[2] + a2[1] + a3[0]
cnt0 = a1.count('0') + a2.count('0') + a3.count('0')
cnt1 = a1.count('1') + a2.count('1') + a3.count('1')
cnt2 = 9 - cnt0 - cnt1

if a1.count('1') == 3 or a2.count('1') == 3 or a3.count('1') == 3:
    if a1.count('2') == 3 or a2.count('2') == 3 or a3.count('2') == 3:
        print('NO')
    elif cnt2 == cnt1 - 1:
        print('YES')
    else:
        print('NO')
elif b1.count('1') == 3 or b2.count('1') == 3 or b3.count('1') == 3:
    if b1.count('2') == 3 or b2.count('2') == 3 or b3.count('2') == 3:
        print('NO')
    elif cnt2 == cnt1 - 1:
        print('YES')
    else:
        print('NO')
elif c1.count('1') == 3 or c2.count('1') == 3:
    if cnt2 == cnt1 - 1:
        print('YES')
    else:
        print('NO')
elif c1.count('2') == 3 or c2.count('2') == 3:
    if cnt2 == cnt1:
        print('YES')
    else:
        print('NO')
elif cnt2 == cnt1 or cnt2 == cnt1 - 1:
        print('YES')
else:
        print('NO')


