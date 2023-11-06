# 전화번호 목록
def solution(phone_book):
    answer = True
    phone_book.sort()
    for i in range(len(phone_book)-1):
        cur = phone_book[i]
        aft = phone_book[i+1]
        if aft[0:len(cur)] == cur:
            answer = False
            break
    return answer
