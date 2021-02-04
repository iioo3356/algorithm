n = int(input())
check = False
cnt_5 = 0
cnt_2 = 0
while (n>=0):
    if n%5 == 0:
        cnt_5 += n//5
        check = True
        break
    else:
        n -= 2
        cnt_2 += 1
if check:
    print(cnt_5 + cnt_2)
else:
    print(-1)
