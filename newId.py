# 2021 KAKAO BLIND RECRUITMENT 신규 아이디 추천
def solution(new_id):
    answer = ""
    for i in range(len(new_id)):
        if ('a' <= new_id[i] <= 'z' or 'A' <= new_id[i] <= 'Z'):
            answer += new_id[i].lower()
        elif ('0' <= new_id[i] <= '9' or new_id[i] == "-" or new_id[i] == "_" or new_id[i] == "."):
            answer += new_id[i]
            
    while (True):
        replaceAnswer = answer.replace('..','.')
        if (replaceAnswer == answer):
            break
        answer = replaceAnswer
        
    if (answer[0] == "."):
        answer = answer[1:]
    if (len(answer) > 0 and answer[len(answer)-1] == "."):
        answer = answer[0:len(answer)-1]       
        
    while (len(answer) < 3 or len(answer) > 15):
        if (len(answer) == 0):
            answer += "a"
            continue;    
            
        if (len(answer) >= 16):
            answer = answer[0:15]
            if (answer[0] == "."):
                answer = answer[1:]
            if (answer[len(answer)-1] == "."):
                answer = answer[0:len(answer)-1]
        if (len(answer) < 3):
            answer += answer[len(answer)-1]

    
    return answer
