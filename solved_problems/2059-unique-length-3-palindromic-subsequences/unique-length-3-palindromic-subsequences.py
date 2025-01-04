class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        lastfirst=[(-1,-1)]*26
        status=[[0]*26 for _ in range(len(s)+1)]
        for i,x in enumerate(s):
            if lastfirst[ord(x)-ord('a')][0]==-1:
                lastfirst[ord(x)-ord('a')]=(i,-1)
            else:
                lastfirst[ord(x)-ord('a')]=(lastfirst[ord(x)-ord('a')][0],i)
            status[i+1]=status[i].copy()
            status[i+1][ord(x)-ord('a')]+=1
        ris=0
        for i,x in enumerate(lastfirst):
            if x[1]==-1:
                continue
            tot=[a - b for a, b in zip(status[x[1]], status[x[0]+1])]
            print(tot)
            for l in tot:
                if l>0:
                    ris+=1
        return ris
