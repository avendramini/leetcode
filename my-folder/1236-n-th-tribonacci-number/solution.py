class Solution:
    def tribonacci(self, n: int) -> int:
        vet=[0,1,1]
        if n<=2:
            return vet[n]
        for i in range(2,n):
            att=sum(vet)
            vet=vet[1:]
            vet.append(att)
        return vet[-1]
