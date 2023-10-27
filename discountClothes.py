# 옷가게 할인 받기
import math
def solution(price):
    answer = price
    if (price >= 500000):
        answer -= price * 0.2
    elif (price >= 300000):
        answer -= price * 0.1
    elif (price >= 100000):
        answer -= price * 0.05
    return math.floor(answer)
