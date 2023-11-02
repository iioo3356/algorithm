from collections import deque

def solution(begin, target, words):
    answer = 0
    
    if target not in words:
        return 0
    else:
        q = deque()
        q.append([begin, 0])
        
        while q:
            item = q.popleft()
            cWord = item[0]
            cCount = item[1]
            if cWord == target:
                return cCount
            
            for word in words:            
                count = 0
                for i in range(len(word)):
                    if (word[i] != cWord[i]):
                        count+=1
                        
                if (count == 1):
                    q.append([word, cCount+1])

    return answer
