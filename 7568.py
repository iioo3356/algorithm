def isBig(a, b):
    if a[0] < b[0] and a[1] < b[1]:
        return True
    return False

N = int(input()) # 전체 사람 수
arr = []
for _ in range(N):
    arr.append(tuple(map(int, input().split())))

# print(arr)
# print(isBig(arr[0], arr[1]))
cnt_arr = []
for i in range(N):
    cnt = 1
    for j in range(0, i):
        if isBig(arr[i], arr[j]):
            # arr[i]가 arr[j] 보다 덩치가 작음
            cnt += 1
    for j in range(i+1, N):
        if isBig(arr[i], arr[j]):
            # arr[i]가 arr[j] 보다 덩치가 작음
            cnt += 1
    cnt_arr.append(str(cnt))
print(" ".join(cnt_arr))
