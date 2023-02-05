a = list(map(int, input().split()))
if (a[0] > 12 or a[1] > 12) or a[0] == a[1]:
    print(1)
else:
    print(0)


