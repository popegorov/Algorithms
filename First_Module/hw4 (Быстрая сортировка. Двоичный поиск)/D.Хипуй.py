class Heap:
    def __init__(self):
        self.a = []

    def Extract(self):
        big = self.a[0]
        self.a[0] = self.a[-1]
        i = 0
        while i * 2 + 1 < len(self.a):
            if self.a[i] < self.a[i * 2 + 1] or i * 2 + 2 < len(self.a)\
               and self.a[i] < self.a[i * 2 + 2]:
                if i * 2 + 2 < len(self.a):
                    if self.a[i * 2 + 1] > self.a[i * 2 + 2]:
                        self.a[i], self.a[i * 2 + 1] = \
                            self.a[i * 2 + 1], self.a[i]
                        i = i * 2 + 1
                    else:
                        self.a[i], self.a[i * 2 + 2] = \
                            self.a[i * 2 + 2], self.a[i]
                        i = i * 2 + 2
                else:
                    self.a[i], self.a[i * 2 + 1] = self.a[i * 2 + 1], self.a[i]
                    i = i * 2 + 1
            else:
                break
        self.a.pop()
        return big

    def Insert(self, x):
        self.a.append(x)
        i = len(self.a) - 1
        while (i - 1) // 2 >= 0:
            if self.a[i] > self.a[(i - 1) // 2]:
                self.a[i], self.a[(i - 1) // 2] = \
                    self.a[(i - 1) // 2], self.a[i]
                i = (i - 1) // 2
            else:
                break

heap = Heap()
n = int(input())
for i in range(n):
    a = list(map(int, input().split()))
    if a[0] == 0:
        heap.Insert(a[1])
    else:
        print(heap.Extract())


