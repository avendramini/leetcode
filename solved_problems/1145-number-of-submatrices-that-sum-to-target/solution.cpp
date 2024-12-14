class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        vector<vector<int> > sum(matrix.size(),vector<int>(matrix[0].size(),0));
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1>=0&&j-1>=0)
                {
                    sum[i][j]=matrix[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
                }
                else if(i-1>=0)
                {
                    sum[i][j]=matrix[i][j]+sum[i-1][j];
                }
                else if(j-1>=0)
                {
                    sum[i][j]=matrix[i][j]+sum[i][j-1];
                }
                else
                    sum[i][j]=matrix[i][j];
            }
        }
        int ris=0;
        for(int lato=0;lato<=n;lato++)
        {
            for(int lato2=0;lato2<=m;lato2++)
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        int iend=i+lato;
                        int jend=j+lato2;
                        if(iend<n&&jend<m)
                        {
                            int tot=sum[iend][jend];
                            if(i-1>=0)
                            tot-=sum[i-1][jend];
                            if(j-1>=0)
                            tot-=sum[iend][j-1];
                            if(i-1>=0&&j-1>=0)
                            tot+=sum[i-1][j-1];

                            if(tot==target)
                            {
                                ris++;
                                //cout<<i<<" "<<j<<" "<<iend<<" "<<jend<<endl;
                            }
                        }
                        
                    }
                }
            }
        }
        return ris;
    }
    
};
