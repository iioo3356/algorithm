T = int(input())
for i in range(T):
    H, W, N = map(int, input().split())
    floor = ''
    room = ''
    if (N%H != 0):
        floor =  str(N%H)
        room = str(N//H+1)
    else:
        floor = str(H)
        room = str(N//H)
    print(floor + room if len(room)==2 else floor+'0' + room)
