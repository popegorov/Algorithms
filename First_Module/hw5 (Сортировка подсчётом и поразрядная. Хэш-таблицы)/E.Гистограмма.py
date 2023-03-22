from collections import defaultdict
a = open('input.txt', 'r')
n = a.read().strip()
simbols = defaultdict(int)
for elem in n:
    if elem != ' ' and elem != '\n':
        simbols[elem] += 1
maxvalue = max(simbols.values())
simbols = sorted(simbols.items())
for i in range(maxvalue):
    for j in range(len(simbols)):
        if simbols[j][1] >= maxvalue - i:
            print('#', end='')
        else:
            print(' ', end='')
    print('\n', end='')
for i in range(len(simbols)):
    print(simbols[i][0], end='')


