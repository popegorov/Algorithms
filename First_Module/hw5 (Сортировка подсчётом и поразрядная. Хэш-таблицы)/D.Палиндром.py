n = int(input())
string = input()
letters = dict()
for elem in string:
    if letters.get(elem, -1) == -1:
        letters[elem] = 1
    else:
        letters[elem] += 1
max_odd = 0
max_letter = ''
pal = ''
flag = True
for elem in sorted(letters.items()):
    pal += elem[0] * (elem[1] // 2)
    if elem[1] % 2 != 0 and flag:
        max_letter = elem[0]
        flag = False
palindrom = pal + max_letter + pal[::-1]
print(palindrom)


