import sys
def queen(row):
    global N,isused1, isused2, isused3, count
    if (row == N):
        # 마지막 줄까지 갈 경우 함수 종료 
        count += 1
        return
    for i in range(N): #i는 col
        if (isused1[i] or isused2[i+row] or isused3[row-i+N-1]):
            continue
        isused1[i] = True
        isused2[i+row] = True
        isused3[row-i+N-1] = True
        queen(row+1)
        isused1[i] = False
        isused2[i+row] = False
        isused3[row-i+N-1] = False

# N = int(input())
N = int(sys.stdin.readline())
isused1 = [False] *40
isused2 = [False] * 40
isused3 = [False]*40
count = 0
queen(0)
print(count)
