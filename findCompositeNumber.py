# 프로그래머스 합성수 찾기
def solution(n):
    answer = 0
    
    for i in range(4, n+1):
        count = 0
        for j in range(1,i+1):
            if (i%j == 0):
                count += 1
        if (count >= 3):
            answer += 1
    return answer
