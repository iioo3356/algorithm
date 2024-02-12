# 2024 KAKAO WINTER INTERNSHIP 가장 많이 받은 선물
def solution(friends, gifts):
    answer = 0
    n = len(friends)
    giftMap = [[0 for _ in range(n)] for _ in range(n)] # giftMap[i][j] = i가 j에게 준 선물 개수
    totalMap = [[0 for _ in range(2)] for _ in range(n)] # totalMap[i][0] = 준 총 개수, totalMap[i][1] = 받은 총 개수
    
    for gift in gifts:
        # 각 친구 사이에서 준 선물 기록 및 총합 선물 기록
        [send, recv] = gift.split(" ")
        sendIdx = friends.index(send)
        recvIdx = friends.index(recv)
        giftMap[sendIdx][recvIdx] += 1
        totalMap[sendIdx][0] += 1
        totalMap[recvIdx][1] += 1
    
    for current in friends:
        count = 0 # current가 다음 달에 받을 선물 예측 개수
        curIdx = friends.index(current)
        for dist in friends:
            if (current == dist):
                continue
            dIdx = friends.index(dist)
            if (giftMap[curIdx][dIdx] > giftMap[dIdx][curIdx]):
                # 내가 해당 친구에게 준 선물이 해당 친구가 내게 준 선물보다 많을 경우   
                count += 1
            elif (giftMap[curIdx][dIdx] == giftMap[dIdx][curIdx]):
                # 내가 해당 친구에게 준 선물이 해당 친구가 내게 준 선물과 같을 경우(0 포함)
                # 선물 지수 비교
                curGiftNum = totalMap[curIdx][0] - totalMap[curIdx][1]
                distGiftNum = totalMap[dIdx][0] - totalMap[dIdx][1]
                if (curGiftNum > distGiftNum):
                    count += 1
        answer = max(answer, count)
        
    return answer
