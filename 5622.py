txt = input()
sum_times = 0
for i in range(len(txt)):
    sum_times+=2
    if 'A'<=txt[i]<='C':
        sum_times += 1
    elif 'D'<=txt[i]<='F':
        sum_times += 2
    elif 'G'<=txt[i]<='I':
        sum_times += 3
    elif 'J'<=txt[i]<='L':
        sum_times +=4
    elif 'M'<=txt[i]<='O':
        sum_times += 5
    elif 'P'<=txt[i]<='S':
        sum_times += 6
    elif 'T'<=txt[i]<='V':
        sum_times+=7
    else:
        sum_times+=8
        
print(sum_times)
