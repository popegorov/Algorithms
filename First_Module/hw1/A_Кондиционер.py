temp = list(map(int, input().split()))
rez = input()
if rez == 'auto':
    print(temp[1])
elif rez == 'heat' and temp[0] < temp[1]:
    print(temp[1])
elif rez == 'freeze' and temp[0] > temp[1]:
    print(temp[1])
else:
    print(temp[0])


