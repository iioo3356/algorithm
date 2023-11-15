def solution(n):
    answer = 0
    columns = [0] * (n+1) # colummns[i] = i번째 row에 지정한 퀸의 column 위치
    def promising(col, i):
        # col : columns
        # i : 현재 위치
        for k in range(1, i):
            if col[i] == col[k] or i-k == abs(col[i]-col[k]):
                # 같은 열이거나 대각선 상에 위치하면 안됨
                return False
        return True
        
    
    def n_queens(col, i):
        # col : columns
        # i : 현재 위치
        nonlocal answer
        if (promising(col, i)):
            if (i==n):
                # 마지막 행까지 모두 배치됨
                answer += 1
                return
            else:
                for j in range(1, n+1):
                    col[i+1] = j
                    n_queens(col, i+1)

    n_queens(columns, 0)
    return answer
