# 호텔 대실
def solution(book_time):
    answer = 0
    room = []
    minuteBook = [0 for _ in range(0, 24*60 + 10)]
    
    for book in book_time:
        [start, end] = book
        startMinute = int(start.split(":")[0])*60 + int(start.split(":")[1])
        endMinute = int(end.split(":")[0])*60 + int(end.split(":")[1]) +10
        for minute in range(startMinute, endMinute):
            minuteBook[minute] += 1
            answer = max(answer, minuteBook[minute])
    
    return answer
