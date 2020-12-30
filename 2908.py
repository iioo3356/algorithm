nums = list(map(int, input().split()))
new_nums = ['','']
for i in range(2):
    new_nums[i] += str(nums[i]%10) + str((nums[i]%100)//10) + str(nums[i]//100)
    new_nums[i] = int(new_nums[i])
print(max(new_nums))
