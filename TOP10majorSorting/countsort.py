def count_sort(nums):
    minval=min(nums)
    maxval=max(nums)
    rangeval=maxval-minval
    count =[0]*(rangeval+1)
    for num in nums:
        count[num-minval]+=1
    sortans=[]
    for id in range(rangeval+1):
        val=id+minval
        sortans.extend([val]*count[id])
    return sortans 
    
nums=[8,-4,2,-1,0]
ans= count_sort(nums.copy())
print(ans)
