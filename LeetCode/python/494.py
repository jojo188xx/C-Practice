def findsum(nums,target):
    total= sum(nums)
    if total <abs(target) or (total+target)%2!=0:
        return 0
    sumpos=(target+total)//2
    dp=[0]*(sumpos+1)
    dp[0]=1
    for num in nums:
        for i in range(sumpos,num-1,-1):
            dp[i]+=dp[i-num]
    return dp[sumpos]
nums=[1,2,3,2]
target=4
print(findsum(nums,target))