a = list(map(int, input().split()))
l1 = a[0]
h1 = a[1]
l2 = a[2]
h2 = a[3]
first = (l1 + l2) * max(h1, h2)
second = (h1 + h2) * max(l1, l2)
third = (l1 + h2) * max(h1, l2)
fourth = (h1 + l2) * max(l1, h2)
if first == min(first, second, third, fourth):
    print((l1 + l2), max(h1, h2))
elif second == min(first, second, third, fourth):
    print(h1 + h2, max(l1, l2))
elif third == min(first, second, third, fourth):
    print(l1 + h2, max(h1, l2))
else:
    print(h1 + l2, max(l1, h2))


