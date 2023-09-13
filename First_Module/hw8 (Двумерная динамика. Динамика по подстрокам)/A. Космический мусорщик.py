coms = [0] * 6
letters = dict()
coms[0] = input()
coms[1] = input()
coms[2] = input()
coms[3] = input()
coms[4] = input()
coms[5] = input()
letters = {'N': 0, 'S': 1, 'W': 2, 'E': 3, 'U': 4, 'D': 5}
com = input().split()
val = int(com[1])
com = com[0]
dp = [[0] * 6 for i in range(val)]

dp[0] = [1] * 6

for num in range(1, val):
    for let in range(6):
        for sim in range(len(coms[let])):
            cur_sim = letters[coms[let][sim]]
            dp[num][let] += dp[num - 1][cur_sim]
        dp[num][let] += 1
print(dp[val - 1][letters[com]])


