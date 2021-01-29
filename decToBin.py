n = int(input())
ans = ''
while (True):
    if  n < 1:
        break
    ans = str(n%2) + ans
    n//=2
if ans == '':
    ans = 0
print(ans)
