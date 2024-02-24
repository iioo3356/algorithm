# 2023 KAKAO BLIND RECRUITMENT 이모티콘 할인행사
from itertools import product

def solution(users, emoticons):
    plusNum = 0 # 최대 이모티콘 플러스 구독 수
    emoticonSales = 0 # 최대 이모티콘 판매액    
    
    availablePercent = [[10,20,30,40] for i in range(len(emoticons))] #이모티콘들의 가능한 할인율
    discountCases = list(product(*availablePercent)) # 가능한 모든 경우의 수

    for discount in discountCases:
        # 모든 경우의 수를 구함
        currentPlusNum = 0 # 현재 플러스 구독 수
        currentEmoticonSales = 0 # 현재 이모티콘 판매액

        for user in users:
            [percent, maxPrice] = user
            total = 0 # 유저가 가능한 모든 이모티콘을 구매하는 비용
            for i in range(len(emoticons)):
                if (discount[i] >= percent):
                    # 일정 할인율 이상이면 모두 삼
                    total += emoticons[i] * (100-discount[i]) * 0.01
            if (total >= maxPrice):
                # 총 가격이 일정 가격 이상이면 이모티콘 플러스만 구독
                currentPlusNum += 1
            else:
                currentEmoticonSales += total
                
        if (currentPlusNum > plusNum):
            # 플러스 가입자를 최대한 늘리는 게 1순위
            plusNum = currentPlusNum
            emoticonSales = currentEmoticonSales
        elif (currentPlusNum == plusNum and currentEmoticonSales > emoticonSales):
            # 2순위 목표인 이모티콘 판매액을 늘림
            emoticonSales = currentEmoticonSales
    
    return [plusNum, emoticonSales]
