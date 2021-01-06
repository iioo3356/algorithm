M = int(input())
N = int(input())
nums = [i for i in range(M, N+1)]
sosu = []
for i in nums:
    flag =False
    if i ==2:
        flag = True
    for j in range(2,i):
        if i % j == 0:
            flag = False
            break
        else:
            flag = True
    if flag == True:
        sosu.append(i)

if (len(sosu)<1):
    print(-1)
else:
    print(sum(sosu))
    print(min(sosu))
