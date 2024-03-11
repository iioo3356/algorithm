# 2021 KAKAO BLIND RECUITMENT 순위 검색
from collections import defaultdict
from bisect import bisect_left,bisect_right

def solution(info, query):
    answer = []
    
    conditionScoreDict = defaultdict(list)
    
    for i in range(len(info)):
        [language, position, career, soulFood, score] = info[i].split()
        for l in [language, "-"]:
            for p in [position, "-"]:
                for c in [career, "-"]:
                    for s in [soulFood, "-"]:
                        if ((l,p,c,s) in conditionScoreDict):
                            conditionScoreDict[(l,p,c,s)].append(int(score))
                        else:
                            conditionScoreDict[(l,p,c,s)] = [int(score)]
                            
        
    
    for condition in conditionScoreDict:
        conditionScoreDict[condition] = sorted(conditionScoreDict[condition])
        

    for q in query:
        count = 0
        scoreX = q.split(" ")[-1]
        condition = q.replace(scoreX, "")
        [language, position, career, soulFood] = condition.split(" and ")
        conditionScore = conditionScoreDict[(language, position, career, soulFood.replace(' ', ''))]
        answer.append(len(conditionScore)-bisect_left(conditionScore, int(scoreX)))

    return answer
