n = int(input())
topics = dict()
text_topic = [0] * n
topic_num = 0
for i in range(n):
    new_topic = int(input())
    if new_topic == 0:
        topics[topic_num] = [input(), 1]
        text_topic[i] = topic_num
        topic_num += 1
    else:
        topics[text_topic[new_topic - 1]][1] += 1
        text_topic[i] = text_topic[new_topic - 1]
    text = input()
max_topic = 0
for elem in topics.values():
    if max_topic < elem[1]:
        max_topic = elem[1]
        max_topic_name = elem[0]
print(max_topic_name)


