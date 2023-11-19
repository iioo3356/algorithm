def solution(rsp):
    answer = ''
    winDict = {"2":"0", "0":"5", "5":"2"}
    for now in rsp:
        answer += winDict[now]
    return answer
