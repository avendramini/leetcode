class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ris(numRows);
        ris[0].push_back(1);
        for(int i=1;i<numRows;i++)
        {   
            for(int j=0;j<=i;j++)
            {
                int att=0;
                if(j-1>=0)
                    att+=ris[i-1][j-1];
                if(j<=i-1)
                    att+=ris[i-1][j];
                ris[i].push_back(att);
            }
        }
        return ris;
    }
};
