def sum_num(n):
    res = n
    for i in range(len(str(n))):
        res += int(str(n)[i])
    return res
num = int(input())
ans = 0
for i in range(1000000):
    if sum_num(i) == num:
        ans = i
        break

print(ans)
