n = int(input())
abc = list(map(int, input().split()))
floors = [0] * (n + 1)
floors[1] = 1
cnt = 1
for i in range(3):
    for j in range(abc[i] + 1, n + 1):
        if floors[j - abc[i]] == 1:
            floors[j] = 1
print(sum(floors))


