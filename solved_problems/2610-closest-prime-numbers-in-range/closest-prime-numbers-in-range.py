class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        is_prime=[1]*int(1e6+1)

        is_prime[0]=False
        is_prime[1]=False
        for i in range(2,right+1):
            if is_prime[i] and i*i<=right:
                j=i*i
                while j<=right:
                    is_prime[j]=False
                    j+=i
        primo=-1
        minimo=1e9
        att=[-1,-1]
        for i in range(left,right+1):
            if is_prime[i]:
                if primo==-1:
                    primo=i
                else:
                    if i-primo<minimo:
                        minimo=i-primo
                        att=[primo,i]
                    primo=i
                    
        return att
