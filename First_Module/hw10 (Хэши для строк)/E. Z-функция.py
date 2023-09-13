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


s = input()
string = Hasher(s)
z = [0] * len(s)
for i in range(1, len(s)):
    l = i - 1
    r = len(s)
    if s[i] == s[0]:
        while l + 1 != r:
            m = (l + r) // 2
            if string.get_hash(0, m - i) == string.get_hash(i, m):
                l = m
            else:
                r = m
    z[i] = l - i + 1
print(*z)


