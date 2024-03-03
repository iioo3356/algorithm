# 2022 KAKAO BLIND RECURITMENT k진수에서 소수 개수 구하기

import math

def isPrime(n):
    # 소수 찾기
    if (n == 1):
        return False
    flag = True
    for i in range(2, int(math.sqrt(n))+1):
        if (n % i == 0):
            flag = False
            break
    return flag

def convert(n, k):
    # 진법 바꾸기
    # 몫이 k 보다 작을 때까지 나머지 연결 후 마지막에는 몫 연결
    nk = ""
    while (n >= k):
        nk = str(n % k) + nk
        n = n // k
    nk = str(n) + nk
    return nk

def solution(n, k):
    answer = 0
    nums = convert(n, k).split("0")
    
    for num in nums:
        if (len(num) > 0):
            if (isPrime(int(num))):
                answer += 1
    return answer
