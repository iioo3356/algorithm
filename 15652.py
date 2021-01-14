def go(cnt):
    global n, m, arr, isused
    if cnt==m:
        print(' '.join(map(str, arr)))
        return
    for i in range(1, n+1):
        if (isused[i] == False):
            arr[cnt] = i
            for j in range(i):
                isused[j] = True 
            go(cnt+1)
            # isused[i] = False
            for j in range(i):
                isused[j] = False
n, m = map(int, input().split())
arr = [0]*m
isused = [False]*(n+1)
go(0)
