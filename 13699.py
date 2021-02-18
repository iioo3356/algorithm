n = int(input())
t = [1, 1, 2] + [0 for _ in range(n)]
for i in range(3,n+1):
    s = 0
    for j in range(i):
        s += t[j]*t[i - 1 - j]
    t[i] = s

print(t[n])
