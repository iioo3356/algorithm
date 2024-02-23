# 2023 KAKAO BLIND RECRUITMENT 개인정보 수집 유효기간
def getDays(date):
    [year, month, day] = date.split(".")
    return int(year) * 12 * 28 + int(month) * 28 + int(day)

def solution(today, terms, privacies):
    answer = []
    todayDays = getDays(today)
    termDict = {}
    
    for term in terms:
        [termType, period] = term.split(" ")
        termDict[termType] = int(period)

    for i in range(len(privacies)):
        privacy = privacies[i]
        [agreeDate, termType] = privacy.split(" ")
        agreeDays = getDays(agreeDate)
        expireDays = agreeDays + 28 * termDict[termType]
        if (todayDays >= expireDays):
            answer.append(i+1)
    return answer
