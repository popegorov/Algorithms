class Hasher:
    def __init__(self, s, x=29, mod=10 ** 9 + 7):
        self.h = [ord(s[0]) - ord("a") + 1]
        for i in range(1, len(s)):
            self.h.append((self.h[i - 1] * x +
                           (ord(s[i]) - ord("a") + 1)) % mod)

        self.power = [1]
        for i in range(1, len(s) + 1):
            self.power.append(self.power[i - 1] * x % mod)

        self.mod = mod

    def get_hash(self, l, r):
        res = self.h[r]
        if l != 0:
            res = (res - self.power[r - l + 1] * self.h[l - 1]) % self.mod

        return res

n = int(input())
s = input()
string = Hasher(s)
rstring = Hasher(s[::-1])
a = [0] * n
for i in range(n):
    maxk = 0
    l = 0
    r = i + 1
    while l + 1 < r:
        m = (l + r) // 2
        if m > maxk and string.get_hash(0, m - 1) ==\
                rstring.get_hash(n - i - 1, n - i + m - 2):
            l = m
        else:
            r = m
    if i == l:
        a[i] = l + 1
    else:
        a[i] = l
print(*a)


