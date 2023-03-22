a = input()
b = []
flag = True
for i in range(len(a)):
    if len(b) == 0 and (a[i] == ')' or a[i] == '}' or a[i] == ']'):
        flag = False
        break
    if a[i] == '(' or a[i] == '{' or a[i] == '[':
        b.append(a[i])
    elif a[i] == ')':
        if b[-1] == '(':
            b.pop()
        else:
            flag = False
    elif a[i] == ']':
        if b[-1] == '[':
            b.pop()
        else:
            flag = False
    elif a[i] == '}':
        if b[-1] == '{':
            b.pop()
        else:
            flag = False
if len(b) != 0:
    flag = False
if flag:
    print('yes')
else:
    print('no')


