import math
t = int(input())
for _ in range(t):    
    n, m = map(int, input().split())
    nf = math.factorial(n)
    mf = math.factorial(m)
    minusf = math.factorial(m-n)
    print(mf//(nf*minusf))
    
    
#------------
# from itertools import combinations
# t = int(input())
# for _ in range(t):    
#     n, m = map(int, input().split())
#     print(len(list(combinations(range(m), n))))
#시간초과
