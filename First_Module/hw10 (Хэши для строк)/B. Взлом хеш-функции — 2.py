def get_hash(string, x):
    result = 0
    for char in string:
        result = (result * x + ord(char)) % 128
    return result


d = {'a': 'b', 'b': 'a'}
s = 'a'
for i in range(12):
    s_n = ''
    for c in s:
        s_n += d[c]
    s += s_n
n = int(input())
a = set()
for i in range(2, 2500, 2):
    a.add(s[i:i + 256])

ans = dict()
for k in a:
    c = k + 'b' * 100
    z = get_hash(c, 7)
    if z not in ans:
        ans[z] = [c]
    else:
        ans[z].append(c)
max_val = 0
for k in ans.keys():
    if len(ans[k]) > max_val:
        max_val = len(ans[k])
        max_key = k
for elem in ans[max_key][:n]:
    print(elem)


