# PCCP 기출문제 1번 / 붕대 감기
def solution(bandage, health, attacks):
    answer = health
    maxHealth = health
    nextAttackIdx = 0
    now = 0
    combo = 1
    while (nextAttackIdx < len(attacks) and answer > 0):
        if (now == attacks[nextAttackIdx][0]):
            answer-=attacks[nextAttackIdx][1]
            nextAttackIdx += 1
            combo = 1
        else:
            if (combo == bandage[0]):
                answer = min(maxHealth, answer + bandage[2] + bandage[1]) 
                combo = 1
            else:
                answer = min(maxHealth, answer + bandage[1])
                combo += 1
        now += 1           

    if (answer <= 0):
        return -1
    return answer
