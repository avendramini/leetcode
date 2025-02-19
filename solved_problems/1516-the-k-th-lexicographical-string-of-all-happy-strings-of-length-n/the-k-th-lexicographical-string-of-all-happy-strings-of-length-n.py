class Solution:
    def generate_strings(self,att,n,ris):
        if len(att)==n:
            ris.append(''.join(att))
            return
        prev='d'
        if  att:
            prev=att[-1]
        for x in ['a','b','c']:
            if x != prev:
                att.append(x)
                self.generate_strings(att,n,ris)
                del att[-1]
        return
    def getHappyString(self, n: int, k: int) -> str:
        ris=[]
        self.generate_strings([], n, ris)
        if k>len(ris):
            return ""
        return ris[k-1]