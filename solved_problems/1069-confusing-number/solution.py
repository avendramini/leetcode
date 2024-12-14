class Solution:
    def confusingNumber(self, n: int) -> bool:
        tot=0
        copia=n
        vett=[0,1,-1,-1,-1,-1,9,-1,8,6]
        while copia>0:
            tot*=10
            if vett[int(copia%10)]==-1:
                return False
            else:
                tot+=vett[int(copia%10)]
                
            copia//=10
        return tot!=n
