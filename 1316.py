num_words = int(input())
num_groups = 0
for i in range(num_words):
    word = input()
    chrs = []
    checked = True
    for j in range(len(word)):
        if word[j] not in chrs:
            chrs.append(word[j])
        else:
            if chrs[-1] != word[j]:
                checked = False
                break
    
    if checked == True:
        num_groups += 1

print(num_groups)
