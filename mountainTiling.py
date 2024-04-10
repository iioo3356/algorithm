# 프로그래머스 산 모양 타일링
def solution(n, tops):
    answer = 0
    invasion = 0 # 바로 옆 삼각형 영역을 침범한 경우의 수
    noInvasion = 0 # 바로 옆 삼각형 영역을 침범하지 않은 경우의 수
    pInvasion = 0 # invasion의 이전 경우의 수
    pNoInvasion = 1 # noInvasion의 이전 경우의 수
    for i in range(len(tops)):
        invasion = pInvasion + pNoInvasion
        if (tops[i] == 1):
            # 위가 있는 삼각형
            noInvasion = pNoInvasion*3 + pInvasion*2
        else:
            # 위 삼각형이 없을 경우
            noInvasion = pNoInvasion*2 + pInvasion
        pInvasion = invasion % 10007
        pNoInvasion = noInvasion % 10007
    answer = (invasion + noInvasion) % 10007
    return answer
