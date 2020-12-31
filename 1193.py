num = int(input())
line_num = 1
cell_num = 1
bottom = 1
top = 1
bottom_up = True

while (True):

    if (cell_num == num):
        break
        
    cell_num += 1 
    # print("cell num : ", cell_num)
    if (bottom_up):
        if (top == 1):
            bottom += 1
            line_num += 1
            bottom_up = False
                
        else:
            top -= 1
            bottom += 1
    else :
        if (bottom == 1):
            top +=1
            line_num+=1
            bottom_up = True

        else:
            bottom -=1
            top += 1
    
print( str(top) + "/" + str(bottom))

