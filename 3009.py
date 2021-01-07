p1 = list(map(int, input().split()))
p2 = list(map(int, input().split()))
p3 = list(map(int, input().split()))

if p1[0] == p2[0]: #case 1
    if p2[1] == p3[1]:
        print(p3[0], p1[1])
    else:
    # p1[1] == p3[1]:
        print(p3[0], p2[1])

elif p2[0] == p3[0] : # case 2
    if p3[1] == p1[1]:
        print(p1[0], p2[1])
    else:
    # p2[1] == p1[1]:
        print(p1[0], p3[1])
else:
# p1[0] == p3[0]:
    if p1[1] == p2[1]:
        print(p2[0], p3[1])
    else:
    # p3[1] == p2[1]:
        print(p2[0], p1[1])
