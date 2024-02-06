# bfs + 브루트포스?
# PCCP 기출문제 2번 석유 시추
from collections import deque

def bfs(r, c, land, visited):
    dr = [0,0,1,-1]
    dc = [1,-1,0,0] 
    count = 0
    visited[r][c] = True
    dq = deque() 
    dq.append([r, c])
    cStart = c
    cEnd = c
    while (len(dq)):
        count+=1
        current = dq.popleft()
        cr = current[0]
        cc = current[1]
        cStart = min(cc, cStart)
        cEnd = max(cc, cEnd)
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if (0 <= nr <len(land) and 0<= nc < len(land[0]) and not visited[nr][nc] and land[nr][nc] == 1):
                dq.append([nr, nc])
                visited[nr][nc] = True
    return [cStart, cEnd, count]

        
        
def solution(land):
    answer = 0
    height = len(land)
    width = len(land[0])
    visited = [[False for _ in range(width)] for _ in range(height)]
    sumOil = [0 for _ in range(width)]
    for r in range(height):
        for c in range(width):
            if (not visited[r][c] and land[r][c] == 1):
                [start, end, count] = bfs(r, c, land, visited)
                for i in range(start, end+1):
                    sumOil[i] += count
                
    answer = max(sumOil)
    return answer
