# 2023 KAKAO BLIND RECRUITMENT 택배 배달과 수거하기
def solution(cap, n, deliveries, pickups):
    answer = 0
    
    deliveries.reverse() # 최대한 멀리씩 할 일을 없애줘야 최소 거리로 이동 가능
    pickups.reverse()
    
    deliverBox = 0 # 배달 중인 박스
    emptyBox = 0 # 수거 중인 박스
    for i in range(n):
        deliverBox += deliveries[i]
        emptyBox += pickups[i]

        while (True):
            if (deliverBox <= 0 and emptyBox <=0):
                # 음수인 경우 이동 과정에서 해당 값만큼 전달(수용량이 남음)
                break
            else:
                # 양수인 경우 이동 시켜야할 박스가 수용 개수보다 더 크기 때문에 한 번 더 해당 위치로 왔다갔다 해야함
                deliverBox -= cap
                emptyBox -= cap
                answer += (n-i)*2
    
    return answer
