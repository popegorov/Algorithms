a = []
command = input().split()
while command[0] != 'exit':
    if command[0] == 'push':
        a.append(command[1])
        print('ok')
    elif command[0] == 'pop':
        if len(a) != 0:
            print(a.pop(0))
        else:
            print('error')
    elif command[0] == 'front':
        if len(a) != 0:
            print(a[0])
        else:
            print('error')
    elif command[0] == 'size':
        print(len(a))
    elif command[0] == 'clear':
        a = []
        print('ok')
    command = input().split()
if command[0] == 'exit':
    print('bye')


