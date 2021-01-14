def go(cnt):
    global n, m, arr, isused
    if cnt == m:
        if arr == sorted(arr):
            print(' '.join(map(str, arr)))
            return
        else:
            return
    for i in range(1, n+1):
        if (isused[i] == False):
            arr[cnt] = i
            isused[i] = True
            go(cnt+1)
            isused[i] = False

n, m = map(int, input().split())
arr = [0]*m
isused = [False]*(n+1)
go(0)
