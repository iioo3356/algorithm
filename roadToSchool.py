# 프로그래머스 등굣길
def solution(m, n, puddles):
    memo = [[0 for _ in range(m)] for _ in range(n)]
    g = [[0 for _ in range(m)] for _ in range(n)]
    
    for puddle in puddles:
        g[puddle[1]-1][puddle[0]-1] = 1
    
    
    memo[0][0] = 1
    for i in range(n):
        for j in range(m):
            if (i==0 and j==0):
                continue
            if (g[i][j] == 0):
                memo[i][j] = (memo[i-1][j] + memo[i][j-1])% 1000000007
    
    return memo[n-1][m-1]
