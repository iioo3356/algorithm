#  2021 KAKAO BLIND RECUITMENT 메뉴 리뉴얼
from itertools import combinations

def solution(orders, course):
    answer = []
    availableCourse = [dict() for _ in range(len(course))] # 개수만큼 케이스를 따로 분류해서 합산
    
    for order in orders:
        charArr = sorted(list(order))
        for i in range(len(course)):
            size = course[i]
            for combination in list(combinations(charArr, size)):
                # 개수만큼 조합 생성
                cStr = "".join(list(combination))
                if (cStr in availableCourse[i]):
                    availableCourse[i][cStr] += 1
                else:
                    availableCourse[i][cStr] = 1
    
    for c in availableCourse:
        if (len(c)):
            maxSales = max(list(c.values()))
            if (maxSales >= 2):
                for item in sorted(list(c.items()), key=lambda x:x[1], reverse=True):
                    # 개수가 가장 많은 순서대로 정렬
                    if (maxSales > item[1]):
                        break
                    answer.append(item[0])
    
    return sorted(answer)
