def merge(list1, list2):
    indexL = 0
    indexR = 0
    ans = []
    while True:
        if indexL == len(list1):
            ans += list2[indexR:]
            break
        elif indexR == len(list2):
            ans += list1[indexL:]
            break
        if list1[indexL] < list2[indexR]:
            ans.append(list1[indexL])
            indexL += 1
        elif list1[indexL] > list2[indexR]:
            ans.append(list2[indexR])
            indexR += 1
        else:
            ans.append(list1[indexL])
            indexL += 1
    return ans

# 합병 정렬
def merge_sort(my_list):
    if len(my_list) <= 1:
        return my_list
    else:
        left_lst = my_list[:len(my_list)//2]
        right_lst = my_list[len(my_list)//2 :]
        return merge(merge_sort(left_lst), merge_sort(right_lst))
print(merge_sort([1, 3, 5, 7, 9, 11, 13, 11]))
print(merge_sort([28, 13, 9, 30, 1, 48, 5, 7, 15]))
print(merge_sort([2, 5, 6, 7, 1, 2, 4, 7, 10, 11, 4, 15, 13, 1, 6, 4]))
