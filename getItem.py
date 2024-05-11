# 프로그래머스 아이템 줍기
from collections import deque
import math 
import heapq

def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    g = [[9 for _ in range(102)] for _ in range(102)]
    dist =  [[math.inf for _ in range(102)] for _ in range(102)]
    dr = [1,0,0,-1]
    dc = [0,1,-1,0]
    
    for rect in rectangle:
        [leftBottomC, leftBottomR, rightTopC, rightTopR] = rect

        for r in range(leftBottomR*2, rightTopR*2+1):
            for c in range(leftBottomC*2, rightTopC*2+1):
                if (leftBottomR*2 < r < rightTopR*2) and (leftBottomC*2 < c < rightTopC*2):
                    g[r][c] = 0
                elif g[r][c] != 0:
                    g[r][c] = 1

                
                    
    q = []
    heapq.heappush(q, (0, [characterY*2, characterX*2]))
    dist[characterY*2][characterX*2] = 0
    
    while(q):
        cd, [cr, cc] = heapq.heappop(q)

        if (dist[cr][cc] < cd):
            continue
                    
        nd = cd + 1
        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]

            if (0<= nr < len(g) and 0<=nc<len(g)):
                if (g[nr][nc] == 1  and dist[nr][nc] > nd):
                    dist[nr][nc] = nd
                    heapq.heappush(q, (nd, [nr, nc]))
        

    answer = dist[itemY*2][itemX*2] //2
    return answer
