def radixsort(nums):
    maxval=max(nums)
    digit=1
    while maxval//digit>0:
        buckets=[[]for _ in range(10)]
        for num in nums:
            cur=(num//digit)%10###混淆
            buckets[cur].append(num)
        nums=[]
        for buk in buckets:
            nums.extend(buk)
        digit*=10
        
    return nums 
        
            
nums=[56,7,3,9,5,0,77]
ans =radixsort(nums)
print (ans) 