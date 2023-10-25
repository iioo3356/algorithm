# 카펫
def solution(brown, yellow):
    answer = []
    # brown은 yellow 영역의 위아래, 양옆을 채우고 모서리 4곳을 더한 값
    # yellow 영역의 가로 세로 크기를 알기 위해서 약수를 구함
    for i in range(1, yellow+1):
        if (yellow % i == 0):
            yr = yellow // i
            yc = i
            if ((yr+yc)*2 + 4 == brown):
                answer.append(yr+2)
                answer.append(yc+2)
                break
    return answer
