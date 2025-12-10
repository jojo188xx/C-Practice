def twosum(nums,target):
    hash={}
    for i , num in enumerate(nums):
        delt=target-num
        if delt in hash:
            return [hash[delt],i]
        hash[num]=i
    return []
nums=[2,6,5,3,0]  
target=8
print(twosum(nums,target))