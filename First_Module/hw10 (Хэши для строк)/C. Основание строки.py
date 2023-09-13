class Hasher:
    def __init__(self, s, x=1009, mod=10 ** 18 + 7):
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

    def compare(self, l1, l2, len):
        if l2 != 0:
            w1 = (self.h[l1 + len - 1] +
                  self.h[l2 - 1] * self.power[len]) % self.mod
        else:
            w1 = self.h[l1 + len - 1]
        if l1 != 0:
            w2 = (self.h[l2 + len - 1] +
                  self.h[l1 - 1] * self.power[len]) % self.mod
        else:
            w2 = (self.h[l2 + len - 1])
        if w1 < w2:
            return -1
        elif w1 == w2:
            return 0
        else:
            return 1

s = input()
flag = True
string = Hasher(s)
for k in range(1, len(s)):
    if string.get_hash(0, len(s) - k - 1) == string.get_hash(k, len(s) - 1):
        print(k)
        flag = False
        break
if flag:
    print(len(s))


