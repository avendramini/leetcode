class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int> > ris;
        for(int i=0;i<mat.size();i++)
        {
            int n=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                    n++;
            }
            ris.push_back({n,i});
        }
        sort(ris.begin(),ris.end());
        vector<int> totali;
        for(int i=0;i<k;i++)
            totali.push_back(ris[i].second);
        return totali;
    }
};
