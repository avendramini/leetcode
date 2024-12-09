class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        cont=0
        for i in range(0,32):
            isa = (a & (1 << i)) != 0
            isb = (b & (1 << i)) != 0
            isc = (c & (1 << i)) != 0

            if isc==0:
                cont+=isa+isb
            elif isa+isb==0:
                    cont+=1
        
        return cont

