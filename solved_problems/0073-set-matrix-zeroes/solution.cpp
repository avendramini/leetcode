class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> col;
        set<int> row;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                    {
                        col.insert(j);
                        row.insert(i);
                    }
            }
        }
        for(auto x: col)
            for(int i=0;i<n;i++)
                matrix[i][x]=0;
        for(auto x: row)
            for(int i=0;i<m;i++)
                matrix[x][i]=0;
    }
};
