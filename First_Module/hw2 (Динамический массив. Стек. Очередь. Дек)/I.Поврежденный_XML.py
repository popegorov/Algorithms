a = input().split('><')
a[0] = a[0][1:]
a[-1] = a[-1][:-1]
stack = []
for i in range(len(a)):
    if a[i][0] == '/' and stack and len(a[i]) - 1 == len(stack[-1][0]):
        cnt = 0
        for o in range(1, len(a[i])):
            if a[i][o] != stack[-1][0][o - 1]:
                cnt += 1
        if cnt == 1:
            stack.append((a[i], i))
        elif a[i][0] == '/' and stack and a[i][1:] == stack[-1][0]:
            stack.pop()
        elif a[i][0] == '/' and len(stack) >= 2 and a[i][1:] == stack[-2][0]:
            stack.pop(-2)
        elif a[i][0] == '/' and len(stack) >= 3 and a[i][1:] == stack[-3][0]:
            stack.pop(-3)
        elif a[i][0] == '/' and len(stack) >= 4 and a[i][1:] == stack[-4][0]:
            stack.pop(-4)
        else:
            stack.append((a[i], i))
    elif a[i][0] == '/' and stack and a[i][1:] == stack[-1][0]:
        stack.pop()
    elif a[i][0] == '/' and len(stack) >= 2 and a[i][1:] == stack[-2][0]:
        stack.pop(-2)
    elif a[i][0] == '/' and len(stack) >= 3 and a[i][1:] == stack[-3][0]:
        stack.pop(-3)
    elif a[i][0] == '/' and len(stack) >= 4 and a[i][1:] == stack[-4][0]:
        stack.pop(-4)
    else:
        stack.append((a[i], i))
if len(stack) == 3:
    c = a[stack[0][1]].rfind('<')
    d = a[stack[0][1]].find('>')
    e = a[stack[1][1]].rfind('<')
    f = a[stack[1][1]].find('>')
    g = a[stack[2][1]].rfind('<')
    h = a[stack[2][1]].find('>')
    if c != -1:
        a[stack[0][1]] = a[stack[0][1]][:c - 1] + '>' + a[stack[0][1]][c:]
    elif d != -1:
        a[stack[0][1]] = a[stack[0][1]][:d + 1] + '<' + a[stack[0][1]][d + 2:]
    elif e != -1:
        a[stack[1][1]] = a[stack[1][1]][:e - 1] + '>' + a[stack[1][1]][e:]
    elif f != -1:
        a[stack[1][1]] = a[stack[1][1]][:f + 1] + '<' + a[stack[1][1]][f + 2:]
    elif g != -1:
        a[stack[2][1]] = a[stack[2][1]][:g - 1] + '>' + a[stack[2][1]][g:]
    else:
        a[stack[2][1]] = a[stack[2][1]][:h + 1] + '<' + a[stack[2][1]][h + 2:]
elif len(stack) == 2:
    if stack[1][0][0] != '/':
        a[stack[1][1]] = '/' + a[stack[1][1]][1:]
    elif stack[0][0].find('/') != -1:
        a[stack[0][1]] = stack[1][0][1:]
    elif stack[0][0].find('<') != -1 or stack[0][0].find('>') != -1:
        a[stack[0][1]] = stack[1][0][1:]
    elif "/" + stack[0][0] != stack[1][0]:
        a[stack[1][1]] = '/' + stack[0][0]
elif len(stack) == 1:
    c = a[stack[0][1]].rfind('<')
    d = a[stack[0][1]].find('>')
    if c != -1:
        a[stack[0][1]] = a[stack[0][1]][:c - 1] + '>' + a[stack[0][1]][c:]
    else:
        a[stack[0][1]] = a[stack[0][1]][:d + 1] + '<' + a[stack[0][1]][d + 2:]
l = '><'.join(a)
print('<' + l + '>')


