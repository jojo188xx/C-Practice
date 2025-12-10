def solve(s):
    n=len(s)
    counting=0
    def expend(left,right):
        cnt=0
        while left>=0 and right<n and s[left]==s[right]:
            cnt+=1
            left-=1
            right+=1
        return cnt
    for i in range(n):
        counting+=expend(i,i)
        counting+=expend(i,i+1)
    return counting
s="abc"

print(solve(s))