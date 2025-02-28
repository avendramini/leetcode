class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        dp=[[[1e9] for _ in range(len(str2)+1)] for _ in range(len(str1)+1)]
        mossa=[[(-1,-1) for _ in range(len(str2)+1)] for _ in range(len(str1)+1)]
        for i in range(len(str1)+1):
            dp[i][0]=i
            mossa[i][0]=(i-1,0)
        for i in range(len(str2)+1):
            dp[0][i]=i
            mossa[0][i]=(0,i-1)
        for i in range(1,len(str1)+1):
            for j in range(1,len(str2)+1):
                dp[i][j]=min([dp[i][j-1]+1,dp[i-1][j]+1])
                if dp[i][j]==dp[i][j-1]+1:
                    mossa[i][j]=(i,j-1)
                else:
                    mossa[i][j]=(i-1,j)
                if str1[i-1]==str2[j-1]:
                    dp[i][j]=min([dp[i-1][j-1]+1,dp[i][j]])
                    if dp[i][j]==dp[i-1][j-1]+1:
                        mossa[i][j]=(i-1,j-1)
                
        ris=[]
        i=len(str1)
        j=len(str2)
        while(i!=0 or j!=0):
            print(f"{i} - {j}")
            m=mossa[i][j]
            
            if m==(i,j-1):
                ris.append(str2[j-1])
            else:
                ris.append(str1[i-1])
            i=m[0]
            j=m[1]
        
        
        return ''.join(ris[::-1])
