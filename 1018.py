def differCount(txt1, txt2):
    count = 0
    for j in range(8):
        if txt1[j] != txt2[j]:
            count += 1
    return count



N, M = map(int, input().split())
board = []
for _ in range(N):
    board.append(input())

# 예제 1
# N = 10
# M = 13
# board = ["BBBBBBBBWBWBW", "BBBBBBBBBWBWB", "BBBBBBBBWBWBW","BBBBBBBBBWBWB",
#          "BBBBBBBBWBWBW","BBBBBBBBBWBWB","BBBBBBBBWBWBW", "BBBBBBBBBWBWB",
#          "WWWWWWWWWWBWB", "WWWWWWWWWWBWB"]
# print(board)

# 예제 2
# N=8
# M = 9
# board = ["BBBBBBBBB","BBBBBBBBB","BBBBBBBBB","BBBBBBBBB",
#          "BBBBBBBBB","BBBBBBBBB","BBBBBBBBB","BBBBBBBBW"]
         
W_start= ["WBWBWBWB" if i%2==0 else "BWBWBWBW" for i in range(8)]
B_start  = ["WBWBWBWB" if i%2==1 else "BWBWBWBW" for i in range(8)]
# print(W_start)
# print(B_start)
cnt_set = set()
# cnt  = 0

for r in range(N-7): # 행 시작 번호
    for c in range(M-7): # 열 시작 번호
        # print("(",r, ", ", c, ") 위치 시작")
        cnt = 0
        for i in range(8):
            # print("검사 중인 행 : ", board[r+i][c:c+8])
            cnt += differCount(board[r+i][c:c+8], B_start[i])
        # print("B로 했을 때 cnt : ", cnt)    
        cnt_set.add(cnt)
        cnt = 0
        for i in range(8):
            # print("검사 중인 행 : ", board[r+i][c:c+8])
            cnt += differCount(board[r+i][c:c+8], W_start[i])
        # print("W로 했을 때 cnt : ", cnt)    
        cnt_set.add(cnt)         

cnt_set = sorted(cnt_set)
print(list(cnt_set)[0])
