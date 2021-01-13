import sys
from collections import Counter

n =int(sys.stdin.readline())
arr = []
for _ in range(n):
    arr.append(int(sys.stdin.readline() ) )
mid = n//2
arr = sorted(arr)
cnt = Counter(arr).most_common()
print(round(sum(arr)/n))
print((sorted(arr))[mid])
if len(arr) >=2 :
    if cnt[0][1] == cnt[1][1]:
        print(cnt[1][0])
    else:
        print(cnt[0][0])
else:
    print(cnt[0][0])
print(max(arr) - min(arr))
