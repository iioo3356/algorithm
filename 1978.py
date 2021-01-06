N = int(input())
arr = list(map(int, input().split()))
count = 0
for i in arr:
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
        count += 1

print(count)
