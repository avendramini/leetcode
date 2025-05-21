class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> col;
        set<int> row;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0){
                    col.insert(j);
                    row.insert(i);
                }
            }

        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(col.find(j)!=col.end() || row.find(i)!=row.end())
                    matrix[i][j]=0;
            }
        }


    }
};