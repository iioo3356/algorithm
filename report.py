# 2022 KAKAO BLIND RECRUITMENT 신고 결과 받기
def solution(id_list, report, k):
    answer = [0 for i in range(len(id_list))] # 각 유저가 메일 수
    g = [[False for i in range(len(id_list))] for i in range(len(id_list))] # g[i][j] = i가 j에게 신고 당했는지 여부
    banNo = [] # 정지될 회원 번호
    
    for r in report:
        [userId, reportId] = r.split(" ")
        userNo = id_list.index(userId)
        reportNo = id_list.index(reportId)
        if (not g[reportNo][userNo]):
            g[reportNo][userNo] = True
            
    for i in range(len(id_list)):
        sumReport = sum(g[i])
        if (sumReport >= k):
            banNo.append(i)

    for b in banNo:
        for j in range(len(id_list)):
            if (g[b][j]):
                answer[j] += 1
    return answer
