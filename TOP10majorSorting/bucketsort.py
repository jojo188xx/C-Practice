def bucketsort(nums):
    minval=min(nums)
    maxval=max(nums)
    cnt=(maxval-minval)//10+1
    bucket=[[]for _ in range(cnt)]
    for num in nums:
        id=(num-minval)//10####遗漏
        bucket[id].append(num)
    res=[]
    for b in bucket:
        b.sort()
        res.extend(b)
    return res
    
    
nums=[56,7,3,9,5,0,77]
ans =bucketsort(nums)
print (ans) 