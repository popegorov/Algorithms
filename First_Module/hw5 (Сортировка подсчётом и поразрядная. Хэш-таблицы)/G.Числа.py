a = list(input())
b = list(input())
alist = [0] * 10
blist = [0] * 10
for i in range(len(a)):
    alist[int(a[i])] += 1
for i in range(len(b)):
    blist[int(b[i])] += 1
number = ''
for i in range(10):
    number += min(alist[i], blist[i]) * str(i)
if number != '' and number[-1] == '0':
    print(0)
elif number != '':
    print(number[::-1])
else:
    print(-1)


