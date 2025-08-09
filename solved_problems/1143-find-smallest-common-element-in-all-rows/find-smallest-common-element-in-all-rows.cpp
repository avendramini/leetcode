class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> m;
        for(int i=0;i<mat.size();i++)
        {
            map<int,int> trov;
            for(int j=0;j<mat[0].size();j++)
            {
                if(trov[mat[i][j]]==0)
                {
                    trov[mat[i][j]]=1;
                    m[mat[i][j]]++;
                }
            }
        }
        for(auto x: m)
        {
            if(x.second==mat.size())
                return x.first;
        }
        return -1;
    }
};