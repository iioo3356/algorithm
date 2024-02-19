# 2024 KAKAO WINTER INTERNSHIP 도넛과 막대 그래프
def solution(edges):
    answer = [0,0,0,0] # 생성한 정점, 도넛 그래프의 수, 막대 그래프의 수, 8자 그래프의 수
    n = 0 # 노드의 개수
    inputs = [0 for _ in range(1000001)] # 각 정점으로 도착하는 간선
    outputs = [0 for _ in range(1000001)] # 각 정점에서 출발하는 간선
    for edge in edges:
        [start, end] = edge
        outputs[start] += 1
        inputs[end] += 1
        n = max(n, start, end) 
        
    for i in range(1,n+1):
        # 노드의 인풋, 아웃풋의 특징에 따라 구분
        if (outputs[i] >= 2 and inputs[i] == 0): # 생성한 정점으로 도착하는 간선 없음 + 도넛,막대,8자 그래프는 2개 이상
            answer[0] = i
        else:
            if (outputs[i] == 0): # 막대 그래프의 가장 위 노드에서 출발하는 간선 없음
                answer[2] += 1
            elif (outputs[i] >= 2 and inputs[i] >=2): # 8자 그래프의 가운데 노드는 2개 이상씩 인풋 아웃풋을 가짐
                answer[3] += 1
    answer[1] = outputs[answer[0]] - answer[2] - answer[3]
    return answer 
