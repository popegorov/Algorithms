n = int(input())
c = list(map(int, input().split()))
k = int(input())
p = list(map(int, input().split()))
for elem in p:
    c[elem - 1] -= 1
for elem in c:
    if elem >= 0:
        print('no')
    else:
        print('yes')


