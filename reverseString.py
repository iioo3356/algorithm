# 문자열 뒤집기
def solution(my_string):
    listString = list(my_string)
    listString.reverse()
    answer = "".join(listString)
    return answer
