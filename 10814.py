import sys
# n = int(input())
n  = int(sys.stdin.readline())
arr = []
for i in range(n):
    # new = input().split()
    new = sys.stdin.readline().split()
    new.append(i)
    arr.append(new)
# print(arr)
arr.sort(key = lambda x: (int(x[0]), x[2]))
for i in arr:
    print(i[0], i[1])
