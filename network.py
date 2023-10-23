def solution(n, computers):
    answer = 0
    visited = [False for i in range(n)]
    for cur in range(n):
        if visited[cur] == False:
            dfs(computers, n, cur, visited)
            answer+=1
    return answer

def dfs(computers, n, cur, visited):
    visited[cur] = True
    for i in range(n):
        if i != cur and computers[cur][i] == 1:
            if visited == False:
                dfs(coumputers, n, i, visited)
