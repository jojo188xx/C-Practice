
def merge(nums):
    if len(nums)<=1:
        return nums
    mid =len(nums)//2
    left=merge(nums[:mid])
    right=merge(nums[mid:])
    return combind(left,right)
def combind(left,right):
    res=[]
    i=j=0
    while i<len(left) and j<len(right):
        if left[i] > right[j]:
            res.append(left[i])
            i+=1
        else:
            res.append(right[j])
            j+=1
    res.extend(left[i:])
    res.extend(right[j:])
    return res

nums=[8,-4,2,-1,0]
ans=merge(nums.copy())
print (ans)