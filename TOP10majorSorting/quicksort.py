import random
def quicksort(nums):
    def partition(low,high):
        posid=random.randint(low,high)
        nums[posid],nums[high]=nums[high],nums[posid]
        posval=nums[posid]
        i=low-1
        for j in range(low,high):
            if nums[j]<posval:
                i+=1
                nums[i],nums[j]=nums[j],nums[i]
        nums[i+1],nums[high]=nums[high],nums[i+1] 
        return i+1  
    def qtloop(low,high):
        if low<high:
            pos=partition(low,high)
            qtloop(low,pos-1)
            qtloop(pos+1,high)

    qtloop(0,len(nums)-1)
    return nums
nums=[8,-4,2,-1,0]
ans=quicksort(nums.copy())
print (ans)
