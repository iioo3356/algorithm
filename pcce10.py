# PCCE 기출문제 10번 / 데이터 분석
def getCompIdx(compStr):
    return 0 if compStr == "code" else 1 if compStr == "date" else 2 if compStr == "maximum" else 3

def solution(data, ext, val_ext, sort_by):
    answer = []
    extIdx = getCompIdx(ext)
    sortIdx = getCompIdx(sort_by)

    for d in data:
        if (d[extIdx] < val_ext):
            answer.append(d)
    answer.sort(key = lambda x: x[sortIdx])
    return answer
