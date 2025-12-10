def heapsort(nums):
    n =len(nums)
    def makeheap(nums,n): 
        for i in range(n//2-1,-1,-1):
            heapify(nums,n,i)
    
    def heapify(nums,n,i):
        largest=i
        left=2*i+1
        right=2*i+2
        if left<n and nums[left]>nums[largest]:
            largest=left
        if right<n and nums[right]>nums[largest]:
            largest=right
        if largest!=i:
            nums[i],nums[largest]=nums[largest],nums[i]
            heapify(nums,n,largest)
    makeheap(nums,n)
    for i in range(n-1,0,-1):
        nums[0],nums[i]=nums[i],nums[0]
        makeheap(nums,i)
    return nums


nums=[8,-4,2,-1,0]
ans=heapsort(nums.copy())
print (ans)