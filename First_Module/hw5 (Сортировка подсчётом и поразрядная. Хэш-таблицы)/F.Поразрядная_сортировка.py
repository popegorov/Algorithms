n = int(input())
numbers = []
print('Initial array:')
for i in range(n):
    m = input()
    numbers.append(m)
print(*numbers, sep=', ')
cnt = 0
buckets = [0] * 10
for i in range(10):
    buckets[i] = []
while cnt != len(numbers[0]):
    print('**********')
    print('Phase', cnt + 1)
    for elem in numbers:
        buckets[int(elem) // 10**cnt % 10].append(elem)
    for i in range(10):
        print('Bucket ' + str(i) + ': ', end='')
        if buckets[i]:
            print(*buckets[i], sep=', ')
        else:
            print('empty')
    numbers = []
    for i in range(10):
        numbers += buckets[i]
    cnt += 1
    for i in range(10):
        buckets[i] = []
print('**********')
print('Sorted array:')
print(*numbers, sep=', ')


