# 게임 맵 최단거리
def solution(maps):
    answer = 0
    dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    dist = [[0 for i in range(len(maps[0]))] for j in range(len(maps))]
    dist[0][0] = 1
    queue = [[0,0]]
    while (len(queue) > 0):
        cur = queue.pop(0)
        for i in range(4):
            nr = dir[i][0] + cur[0]
            nc = dir[i][1] + cur[1]
            if (0 <= nr < len(maps) and 0 <= nc < len(maps[0])):
                if (maps[nr][nc] == 1 and dist[nr][nc] == 0):
                    dist[nr][nc] = dist[cur[0]][cur[1]] + 1;
                    queue.append([nr, nc])

    answer = dist[len(maps)-1][len(maps[0])-1]
    if (answer == 0):
        answer = -1
    return answer
