def dp(i, j):
    global n, m, prev
    if prev.get((i, j), -1) != -1:
        return prev[(i, j)]
    elif i == 0 and j == 0:
        return 1
    elif i <= 1 and j <= 1:
        return 0
    elif i == 0:
        prev[(i, j)] = dp(i + 1, j - 2)
        return prev[(i, j)]
    elif j == 0:
        prev[(i, j)] = dp(i - 2, j + 1)
        return prev[(i, j)]
    elif i == 1:
        prev[(i, j)] = dp(i - 1, j - 2) + dp(i + 1, j - 2)
        return prev[(i, j)]
    elif j == 1:
        prev[(i, j)] = dp(i - 2, j - 1) + dp(i - 2, j + 1)
        return prev[(i, j)]
    elif i == n - 1 and j == m - 1:
        prev[(i, j)] = dp(i - 1, j - 2) + dp(i - 2, j - 1)
        return prev[(i, j)]
    elif i == n - 1:
        prev[(i, j)] = dp(i - 2, j - 1) + dp(i - 2, j + 1) + dp(i - 1, j - 2)
        return prev[(i, j)]
    elif j == m - 1:
        prev[(i, j)] = dp(i - 2, j - 1) + dp(i + 1, j - 2) + dp(i - 1, j - 2)
        return prev[(i, j)]
    else:
        prev[(i, j)] = dp(i - 2, j - 1) + dp(i + 1, j - 2) \
                       + dp(i - 1, j - 2) + dp(i - 2, j + 1)
        return prev[(i, j)]

n, m = map(int, input().split())
prev = dict()
if n <= 2:
    if n == 1:
        print(0)
    else:
        if m % 4 == 3:
            print(1)
        else:
            print(0)
elif m <= 2:
    if n == 1:
        print(0)
    else:
        if n % 4 == 3:
            print(1)
        else:
            print(0)
else:
    print(dp(n - 1, m - 1))


