import sys
N = int(sys.stdin.readline())
arr = []
for _ in range(N):
    arr.append(list(map(int, sys.stdin.readline() ) ) )
# print(arr)
x_arr = [i[0] for i in arr]
y_arr = []
for _ in range(N):
    min_x =min(x_arr)
    # print("min_x", min_x)
    if min_x == 100001:
        break
    min_x_idx = x_arr.index(min_x)
    if x_arr.count(min_x) == 1:
        # print("x_arr.count(min_x) == 1")
        print(arr[min_x_idx][0], arr[min_x_idx][1])
        x_arr[min_x_idx] = 100001
    else:
        # print("x_arr.count(min_x) > 1")
        for i in range(x_arr.count(min_x)):
            # print("x_arr", x_arr)
            min_x_idx = x_arr.index(min_x)
            # print("min_x_idx: ", x_arr.index(min_x))
            y_arr.append(arr[min_x_idx][1])
            # print("arr[min_x_idx][1]",arr[min_x_idx][1])
            x_arr[min_x_idx] = 100001
        # print("y_arr : ")
        # print(y_arr)

        while(True):
            if min(y_arr) == 100001:
                break
            min_y  = min(y_arr)
            min_y_idx = y_arr.index(min_y)
            # print(arr[min_y_idx])
            print(arr[min_x_idx][0], min_y)
            y_arr[min_y_idx] = 100001
