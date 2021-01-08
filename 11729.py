def hanoi(n, start, mid, end):
    if n==1:
        # 원판이 1개인 경우 바로 옮김
        print(start, end)
    else:
        hanoi(n-1, start, end, mid)
        # 가장 밑에 있는 원판을 제외한 원판들을 가운데로 옮김
        print(start, end)
        # 밑에 있는 원판을 끝으로 옮김
        hanoi(n-1, mid, start, end)
        # 가운데에 있는 원판들을 끝으로 옮김
num = int(input())
print(2**num -1)
hanoi(num, 1, 2, 3)
