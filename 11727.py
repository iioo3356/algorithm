arr = [0] * 1001
n = int(input())
for i in range(n+1):
    if i <= 1:
        arr[i] = i
    elif i == 2:
        arr[i] = 3
    else:
        arr[i] = (arr[i-1]+2*arr[i-2])%10007 
print(arr[n])
