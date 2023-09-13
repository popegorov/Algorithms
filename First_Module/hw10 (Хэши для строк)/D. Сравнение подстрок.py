class Hasher:
    def __init__(self, s, x=97, mod=10 ** 18 + 7):
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
q = int(input())
for i in range(q):
    l, a, b = map(int, input().split())
    if string.get_hash(a, l + a - 1) == string.get_hash(b, l + b - 1):
        print(0)
    else:
        left = 0
        right = l
        while left + 1 < right:
            m = (left + right) // 2
            if string.get_hash(a, a + m - 1) == string.get_hash(b, b + m - 1):
                left = m
            else:
                right = m
        if s[a + left] > s[b + left]:
            print(1)
        else:
            print(-1)


