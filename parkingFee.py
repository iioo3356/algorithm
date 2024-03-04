# 2022 KAKAO BLIND RECRUITMENT 주차 요금 계산
import math

def solution(fees, records):
    answer = []
    
    [defaultTime, defaultFee, unitTime, unitFee] = fees
    
    carRecord = {} # key: 차 번호 value: 누적 시간
    maxTime = 23 * 60 + 59
    
    for record in records:
        [time, carNum, desc] = record.split(" ")
        # 주차한 시간 = -입차 시간 +출차 시간
        [hour, minute] = time.split(":")
        timeValue = int(hour) * 60 + int(minute)
        if (desc == "IN"):
            timeValue *= -1 
        if (carNum in carRecord):
            carRecord[carNum] += timeValue 
        else:
            carRecord[carNum] = timeValue
    
    sortedCar = sorted(list(carRecord.items()), key=lambda x:x[0]) # 차 번호가 작은 순서대로 정렬

    for car in sortedCar:
        [carNum, time] = car
        fee = defaultFee # 기본 시간 이하인 경우 기본 요금 청구
        if (time <= 0): 
            # 입차만 하고 출차하지 않은 경우 23:59에 출차한 것으로 간주
            time += maxTime 
        if (time > defaultTime):
            # 기본 시간 초과한 경우 초과 금액 계산
            fee += unitFee * math.ceil((time-defaultTime) / unitTime)
        answer.append(fee)
        
    return answer
