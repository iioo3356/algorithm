# 네트워크 
def solution(n, computers):
    answer = 0
    visited = [False for i in range(n)]
    for cur in range(n):
        if visited[cur] == False:
            bfs(computers, n, cur, visited)
            answer+=1
    return answer

def dfs(computers, n, cur, visited):
    visited[cur] = True
    for i in range(n):
        if i != cur and computers[cur][i] == 1:
            if visited[i] == False:
                dfs(computers, n, i, visited)
                
                
def bfs(computers, n, cur, visited):
    visited[cur] = True
    st = []
    st.append(cur)
    print(cur)
    while len(st) > 0:
        item = st.pop(0)
        visited[item] = True
        for i in range(n):
            if i != item and computers[item][i] == 1:
                if visited[i] == False:
                    st.append(i)
