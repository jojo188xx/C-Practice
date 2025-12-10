def insertsort(nums):
    n=len(nums)
    for i in range(1,n):
        tmp=nums[i]
        j=i-1
        while j>=0 and nums[j]>tmp:
            nums[j+1]=nums[j]
            j-=1
        nums[j+1]=tmp
    return nums
nums=[8,-4,2,-1,0]
ans=insertsort(nums.copy())
print (ans)