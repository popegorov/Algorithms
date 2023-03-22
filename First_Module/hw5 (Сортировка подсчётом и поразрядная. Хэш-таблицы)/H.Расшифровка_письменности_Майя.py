from collections import defaultdict
g, s = map(int, input().split())
key_word = input()
a = input()
obraz = defaultdict(int)
current = defaultdict(int)
mistakes = len(key_word)
cnt = 0
for elem in key_word:
    obraz[elem] += 1
for i in range(s):
    if current[a[i]] < obraz[a[i]]:
        mistakes -= 1
    else:
        mistakes += 1
    current[a[i]] += 1
    if i >= g:
        if current[a[i - g]] > obraz[a[i - g]]:
            mistakes -= 1
        else:
            mistakes += 1
        current[a[i - g]] -= 1
    if mistakes == 0:
        cnt += 1
print(cnt)


