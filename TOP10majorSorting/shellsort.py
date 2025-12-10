def shell_sort(nums):
    n=len(nums)
    gap=n//2
    while gap>0:
        for i in range(gap,n):
            tmp=nums[i]
            j=i-gap
            while j>=0 and nums[j]>tmp:
                nums[j+gap]=nums[j]
                j-=gap
            nums[j+gap]=tmp
        gap//=2
    return nums
        
nums=[8,-4,2,-1,0]
ans=shell_sort(nums.copy())
print (ans)