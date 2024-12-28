class Solution:
    def rico(self, pos, closed, k,nums,dp,prefix):
        if closed==3:
            dp[pos][closed]=0
            return dp[pos][closed]
        if pos+k>len(nums):
            return -1e9
        if dp[pos][closed]!=-1:
            return dp[pos][closed]
        rico1=self.rico(pos+k,closed+1,k,nums,dp,prefix)+prefix[pos+k]-prefix[pos]
        rico2=self.rico(pos+1,closed,k,nums,dp,prefix)
        massimo=max([rico1,rico2])
        dp[pos][closed]=massimo
        return dp[pos][closed]
    
        
        
        
        
    
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        prefix=[0]*(len(nums)+1)
        for i,x in enumerate(nums):
            prefix[i+1]=prefix[i]+x
        dp=[[-1 for _ in range(4)] for _ in range(len(nums)+1)]
        
        self.rico(0,0,k,nums,dp,prefix)

        ris=[]
        pos=(0,0)
        while pos[1]!=3:
            print("qua")
            if pos[0]+k<=len(nums) and pos[1]<3 and dp[pos[0]+k][pos[1]+1]+prefix[pos[0]+k]-prefix[pos[0]]==dp[pos[0]][pos[1]]:
                ris.append(pos[0])
                pos=(pos[0]+k,pos[1]+1)
            else:
                pos=(pos[0]+1,pos[1])
        return ris
            


