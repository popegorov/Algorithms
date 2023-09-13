from collections import defaultdict
n, k = map(int, input().split())
string = input()
cnt_letters = defaultdict(int)
max_cnt = 0
right = 0
cur_cnt = 0
for left in range(n):
    while right < len(string) and cnt_letters[string[right]] < k:
        cnt_letters[string[right]] += 1
        cur_cnt += 1
        right += 1
    if cur_cnt > max_cnt:
        max_cnt = cur_cnt
        max_first = left
    cur_cnt -= 1
    cnt_letters[string[left]] -= 1
print(max_cnt, max_first + 1)


