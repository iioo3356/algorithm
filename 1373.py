n = input()
num = 0
for i in range(len(n)):
    if n[i] == '1':
        num += pow(2, len(n)-1-i)

ans = ''
while (True):
    if  num < 8:
        ans = str(num) + ans
        break
    ans = str(num%8) + ans
    num//=8
if ans == '':
    ans = 0
print(ans)

#2진수 -> 10진수 -> 8진수 구현을 해봤지만 시간 초과가 떠서 내장 함수 이용

n = input()
print(oct(int(n, 2))[2:])
