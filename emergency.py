def solution(emergency):
    answer = []
    sortedEmergency = sorted(emergency, reverse = True)   
    for e in emergency:
        answer.append(sortedEmergency.index(e)+1)
    
    return answer
