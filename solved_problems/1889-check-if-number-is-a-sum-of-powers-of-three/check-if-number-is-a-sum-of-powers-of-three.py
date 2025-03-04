class Solution:
    def rico(self, n,powers,index):
        if n==0:
            return True
        if index==-1:
            return False
        ris=False
        if n>=powers[index]:
            ris|=self.rico(n-powers[index],powers,index-1)
        ris|=self.rico(n,powers,index-1)
        return ris
    def checkPowersOfThree(self, n: int) -> bool:
        powers=[3**i for i in range(15)]
        return self.rico(n,powers,len(powers)-1)
        