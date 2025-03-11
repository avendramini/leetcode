class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        m={'a':[len(s)]*(len(s)+1), 'b':[len(s)]*(len(s)+1), 'c':[len(s)]*(len(s)+1)}
        
        for i,x in enumerate(s[::-1]):
            m[x][len(s)-i-1]=min([m[x][len(s)-i],len(s)-i-1])
            for y in ['a','b','c']:
               m[y][len(s)-i-1]=min([m[y][len(s)-i],m[y][len(s)-i-1]])
        ris=0
        print(m)
        for i,x in enumerate(s):
            right=i
            lista=['a','b','c']
            lista.remove(x)
            for y in lista:
                right=max([right,m[y][i]])
            print(i,right)
            ris+=len(s)-right
        return ris
