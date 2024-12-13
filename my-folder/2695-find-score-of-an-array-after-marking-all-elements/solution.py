class Solution:
    def findScore(self, nums: List[int]) -> int:
        vis=[0]*len(nums)
        l=[]
        for i,x in enumerate(nums):
            l.append((x,i))
        l=sorted(l)
        cont=0
        for x in l:
            if not vis[x[1]]:
                cont+=x[0]
                vis[x[1]]=True
                if x[1]!=len(nums)-1:
                    vis[x[1]+1]=True
                if x[1]!=0:
                    vis[x[1]-1]=True

        return cont        
