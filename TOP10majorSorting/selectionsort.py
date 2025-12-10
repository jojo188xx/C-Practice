def selection_sort(nums):
    n=len(nums)
    for i in range(n-1):
        min_id=i
        for j in range(i+1,n):
            if nums[j]<nums[min_id]:
                min_id=j
        nums[i],nums[min_id]=nums[min_id],nums[i]
    return nums
nums=[8,-4,2,-1,0]
ans=selection_sort(nums.copy())
print (ans)