# 가장 먼 노드
from collections import deque

def solution(n, edge):
    answer = 0
    g = [[] for i in range(n+1)]
    dist = [-1 for i in range(n+1)]

    for e in edge:
        g[e[0]].append(e[1])
        g[e[1]].append(e[0])
    
    q = deque()
    q.append(1)
    dist[1] = 0
    while (len(q)):
        cur = q.popleft()
        for e in g[cur]:
            if (dist[e] == -1):
                q.append(e)
                dist[e] = dist[cur] + 1
                
    for d in dist:
        if (d == max(dist)):
            answer+=1
    return answer
