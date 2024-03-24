# 프로그래머스 숫자 카드 나누기
import math

def solution(arrayA, arrayB):
    answer = 0
    gcdA = arrayA[0]
    gcdB = arrayB[0]
    
    for a in arrayA:
        gcdA = math.gcd(gcdA, a)
        
    
    for b in arrayB:
        gcdB = math.gcd(gcdB, b)
    
    if (gcdA != gcdB):
        if (gcdA > 1):
            for b in arrayB:
                if (b % gcdA == 0):
                    gcdA = 0
                    break
        if (gcdB > 1):
            for a in arrayA:
                if (a % gcdB == 0):
                    gcdB = 0
                    break
        answer = max(gcdA, gcdB)
    else:
        answer = 0

    return answer
