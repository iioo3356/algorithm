# 더 맵게
import heapq

def solution(scoville, K):
    answer = 0
    h = []
    for i in scoville:
        heapq.heappush(h, i)
    
    while (len(h)>=2):
        m = heapq.heappop(h)
        if (m >= K):
            heapq.heappush(h, m)
            break
        else:
            answer+=1
            m2 = heapq.heappop(h)
            heapq.heappush(h, m + m2 * 2)
    if (h[0] < K):
        answer = -1 
    return answer
