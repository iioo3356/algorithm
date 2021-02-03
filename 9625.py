n = int(input())
# memo = [[1,0]] *(n+1)
memo = [[1,0]] + [[0,0]] *(n)
#memo[0] = (버튼을 누르기 전 A 개수, B 개수) 
for i in range(1, n+1):
    numA = memo[i-1][1]
    # print(i, "번 누를 때 A 개수: ", numA)
    numB = memo[i-1][0] + memo[i-1][1]
    # print(i, "번 누를 때 B 개수: ", numB)
    memo[i] = list((numA, numB))
    # print(memo)
print(memo[n][0], memo[n][1])
