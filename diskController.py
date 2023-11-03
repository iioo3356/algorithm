#디스크 컨트롤러
import heapq

def solution(jobs):
    answer = 0
    i = 0
    start = -1
    now = 0
    
    h = []
    while (i < len(jobs)):
        for job in jobs:
            if start < job[0] <= now:
                heapq.heappush(h,[job[1], job[0]])
        if (len(h) > 0):
            cur = heapq.heappop(h)
            start = now
            now += cur[0]
            answer += now - cur[1]
            i+=1
        else:
            now+=1
    return int(answer/len(jobs))
