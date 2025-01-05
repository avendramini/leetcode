class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        lis=[]
        for x in shifts:
            lis.append((x[0],-1 if x[2]==0 else 1))
            lis.append((x[1]+1,1 if x[2]==0 else -1))
        lis.sort(key=lambda x : x[0])
        print(lis)
        ris=""
        j=0
        cont=0
        for i,x in enumerate(s):
            
            while j<len(lis) and lis[j][0]<=i:
                cont+=lis[j][1]
                j+=1
            ris+=chr((ord(x)-ord('a')+cont)%26+ord('a'))
        return ris