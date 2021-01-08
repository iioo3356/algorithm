N, M = map(int, input().split())
cards = list(map(int, input().split()))
sum_arr = set()

for i in range(N):
    if cards[i] <= M-2:
        for j in range(i+1, N):
            if cards[j] <= M-2:
                for k in range(j+1, N):
                    if cards[i]+cards[j]+cards[k] <= M:
                        sum_arr.add(cards[i]+cards[j]+cards[k])

sum_arr = sorted(sum_arr)
# print(sum_arr)
print(list(sum_arr)[-1 ])
