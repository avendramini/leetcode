class Solution {
public:
    vector<int> risolvi(vector<vector<int>> matrix,int n,int m)
    {
        if(n==1&&m==1)
            return {matrix[0][0]};
        if(n<=0||m<=0)
            return {};
        vector<int> ris;
        for(int i=0;i<m;i++)
        {
            ris.push_back(matrix[0][i]);
        }
        for(int j=1;j<n;j++)
        {
            ris.push_back(matrix[j][m-1]);
        }
        if(n-1!=0)
        for(int j=m-2;j>=0;j--)
            ris.push_back(matrix[n-1][j]);
        if(m-1!=0)
        for(int i=n-2;i>=1;i--)
        {
            ris.push_back(matrix[i][0]);
        }
        if(n-2>0){
        vector<vector<int>> ma(n-2);
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                ma[i-1].push_back(matrix[i][j]);
            }
        }
        vector<int> app=risolvi(ma,n-2,m-2);
        for(auto x: app)
            ris.push_back(x);
        }
        return ris;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        return risolvi(matrix,n,m);
        

    }
};
