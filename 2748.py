n = int(input())
memo = [0] *(n+1)
for i in range(1, n+1):
    if i<3:
        memo[i] = 1
    else:
        memo[i] = memo[i-2] + memo[i-1]

print(memo[n])
