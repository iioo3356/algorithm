import math
def dist(x1,x2,y1,y2):
    return math.sqrt((x1-x2)**2 + (y1-y2)**2)
numTestCases = int(input())
for _ in range(numTestCases):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    cnt = 0
    # print(dist(x1,x2, y1, y2)) 

    if dist(x1,x2, y1, y2) == 0:
        # 중심이 일치
        if r1 == r2:
            print(-1)
        else: # 한 원이 다른 원 안에 들어가 있음
            print(0)
    else:
        if abs(r1-r2) < dist(x1,x2, y1, y2) < r1+ r2:
            # 두 점에서 만남
            print(2)
        elif dist(x1,x2, y1, y2) == r1 + r2 or dist(x1,x2, y1, y2) == abs(r1-r2):
            # 한 점에서 만남
            print(1)
        elif dist(x1, x2, y1, y2) > r1 + r2 or dist(x1,x2, y1, y2) < abs(r1-r2):
            # 만나지 않음
            print(0)
