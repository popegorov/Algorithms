n,  m = map(int, input().split())
nabl = [[-1, 0]]
for i in range(m):
    b, e = map(int, input().split())
    nabl.append([b, -1])
    nabl.append([e, 1])
nabl.sort()
cnt = 0
cur_cnt = 0
for i in range(1, len(nabl)):
    if cur_cnt == 0:
        cnt += nabl[i][0] - nabl[i - 1][0] - 1
    if nabl[i][1] == -1:
        cur_cnt += 1
    else:
        cur_cnt -= 1
cnt += n - 1 - nabl[-1][0]
print(cnt)


