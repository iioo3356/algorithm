# 가장 큰 수
def solution(numbers):
    answer = ''
    stringArr = []
    for num in numbers:
        stringArr.append(str(num))
    stringArr.sort(key=lambda num: num*3, reverse=True) 
    answer = str(int(''.join(stringArr)))
    return answer
