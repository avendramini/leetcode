class Solution:
    def findLonelyPixel(self, picture: List[List[str]]) -> int:
        n=len(picture)
        m=len(picture[0])
        row_count=[0]*n
        col_count=[0]*m
        for i in range(n):
            for j in range(m):
                if picture[i][j]=='B':
                    row_count[i]+=1
                    col_count[j]+=1
        ris=0
        for i in range(n):
            for j in range(m):
                if picture[i][j]=='B':
                    if row_count[i]==1 and col_count[j]==1:
                        ris+=1
        return ris