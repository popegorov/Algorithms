n, m = map(int, input().split())
letters = [0] * 26
for i in range(n):
    a = list(input())
    for j in range(n):
        letters[ord(a[j]) - ord('A')] += 1
for i in range(m):
    b = list(input())
    for j in range(len(b)):
        letters[ord(b[j]) - ord('A')] -= 1
for i in range(26):
    print(chr(i + ord('A')) * letters[i], end='')


