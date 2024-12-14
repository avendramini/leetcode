class Solution:
    def maxLength(self, ribbons: List[int], k: int) -> int:
        low=1
        up=1e5
        ris=0
        while low<=up:
            
            mid=(low+up)//2
            
            cont=0
            for x in ribbons:
                cont+=x//mid
            if cont>=k:
                ris=max([ris,mid])
                low=mid+1
            elif cont<k:
                up=mid-1
        return int(ris)
