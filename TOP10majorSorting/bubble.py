def bubble(nums):
    n=len(nums)
    for i in range(n-1):
        swapped=False
        for j in range(n-i-1):
            if nums[j]>nums[j+1]:
                nums[j],nums[j+1]=nums[j+1],nums[j]
                swapped=True
        if not swapped:
            break
    return nums
nums=[8,-4,2,-1,0]
bubble(nums)
stnums=bubble(nums)
print(stnums)

