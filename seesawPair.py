# 시소 짝꿍
def solution(weights):
    numberList = [0 for _ in range(100, 1001)] # numberList[0] : weight가 100인 사람의 수
    for w in weights:
        numberList[w-100] += 1
    for i in range(0, len(numberList)):
        if (numberList[i] > 0):
            if (numberList[i] > 1):
                answer += numberList[i] * (numberList[i]-1) / 2
            realNum = 100 + i
            ratio = [3/2, 4/3, 2]
            for r in ratio:
                pairNum = r * realNum
                if (pairNum <= 1000 and int(pairNum) == pairNum):
                    if (numberList[int(pairNum)-100] > 0):
                        answer += numberList[i] * numberList[int(pairNum)-100]
        
    return answer
