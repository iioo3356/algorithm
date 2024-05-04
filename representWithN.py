# 프로그래머스 N으로 표현
def solution(N, number):
    answer = 0
    memo = [[] for _ in range(9)] # N을 i번 사용했을 때 나오는 모든 수를 메모
    
    for i in range(1,9):
        availableNum = set()
        availableNum.add(int(str(N)*i)) # N, NN, NNN 형태
        # memo[i] = memo[i-j] (+ or - or * or //) memo[j]
        for j in range(1,i):
            for left in memo[i-j]:
                for right in memo[j]:
                    availableNum.add(left + right)
                    minus = left - right
                    if (minus > 0):
                        availableNum.add(minus)
                    availableNum.add(left * right)                    
                    if (right > 0):
                        availableNum.add(left // right)
        if (number in availableNum):
            return i
        else:
            memo[i] = availableNum
                    
    return -1
