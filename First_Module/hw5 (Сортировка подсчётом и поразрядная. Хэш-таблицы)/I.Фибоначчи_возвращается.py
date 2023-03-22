fib0 = 1
fib1 = 1
numbers = []
n = int(input())
for i in range(n):
    new = int(input())
    numbers.append([new, i])
numbers.sort()
for i in range(n):
    if numbers[i][0] == fib1 or numbers[i][0] == fib0:
        numbers[i][0] = 1
    elif numbers[i][0] < fib1:
        numbers[i][0] = 0
    else:
        while numbers[i][0] > fib1:
            fib1, fib0 = fib1 + fib0, fib1
        if numbers[i][0] == fib1:
            numbers[i][0] = 1
        else:
            numbers[i][0] = 0
numbers.sort(key=lambda x: x[1])
for elem in numbers:
    if elem[0] == 1:
        print('Yes')
    else:
        print('No')


