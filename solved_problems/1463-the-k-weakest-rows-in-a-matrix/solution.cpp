class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int> > sum(mat.size());
        for(int i=0;i<mat.size();i++)
        {
            sum[i].first=0;
            sum[i].second=i;
            for(int j=0;j<mat[i].size();j++)
            {
                sum[i].first+=mat[i][j];
            }
        }
        sort(sum.begin(),sum.end());
        vector<int> indici;
        for(int i=0;i<k;i++)
        {
            indici.push_back(sum[i].second);
        }
        return indici;


    }
};
