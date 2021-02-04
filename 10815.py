import sys
n = int(sys.stdin.readline())
cards = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))

def search(num, arr, left, right):
    if left > right:
        return 0
    mid = (left + right) //2
    if num == arr[mid]:
        return 1
    elif num < arr[mid]:
        return search(num, arr, left, mid-1)
    else:
        return search(num, arr, mid+1, right)
answers = []
cards.sort()
for i in range(m):
    answers.append(search(nums[i], cards, 0, n-1))
print(' '.join(list(map(str, answers))))
