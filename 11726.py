# arr = [0] * 1001
# def dp(n):
#     if n < 3:
#         arr[n] = n
#         return n
#     if  arr[n] != 0:
#         return arr[n]
#     else:
#         arr[n] = (dp(n-1) + dp(n-2)) %10007
#         return d[n]

# n = int(input())
# print(dp(n)) --> Recursion error 발생, 수정
#------------------------------------------------------
arr = [0] * 1001
n = int(input())
for i in range(n+1):
    if i < 3:
        d[i] = i
    else:
        d[i] = (d[i-1]+d[i-2])%10007 
print(d[n])
