# 2022 KAKAO BLIND RECURITMENT 양궁대회

from collections import deque

def solution(n, info):
    answer = []
    dq = deque([(0,[0,0,0,0,0,0,0,0,0,0,0])])
    maxGap = 0
    while (dq):
        # position이 커질수록 낮은 점수를 맞히게 됨
        position, score = dq.popleft()
        if (sum(score) == n):
            # 모든 화살을 다 쏜 경우
            # 점수 계산
            lion = 0
            apeach = 0
            for i in range(11):
                pos = 10 - i
                if (info[i] >= score[i] and info[i]>0):
                    apeach += pos
                elif (score[i] > info[i]):
                    lion += pos
            if (lion > apeach):
                # 점수 차이 계산
                gap = lion - apeach
                if (maxGap <= gap):
                    answer = score
                    maxGap = gap
        elif (sum(score) < n):
            # 계속 어피치보다 1발씩 더 쏘다가 N개보다 더 많이 쏜 경우는 무시
            if (position == 10):
                # 모든 화살을 쏘지 않았는데 마지막 0점을 쏴야하는 경우
                # 몰아서 0점에 쏨
                temp = score.copy()
                temp[position] = n - sum(score)
                dq.append((0, temp))
            else:
                # 해당 점수에서 어피치보다 득점하는 경우
                temp1 = score.copy()
                temp1[position] = info[position] + 1
                dq.append((position+1, temp1))
                # 해당 점수에서 득점하지 않고 화살을 아끼는 경우
                temp2 = score.copy()
                temp2[position] = 0
                dq.append((position+1, temp2))

    if (len(answer) == 0):
        answer.append(-1)
    return answer
