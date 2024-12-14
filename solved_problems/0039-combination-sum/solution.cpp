class Solution {
public:
    void back(int pos,vector<int>& scelte,int rim,vector<int> &candidates,vector<vector<int> >& ris)
    {
        if(rim==0)
        {
            ris.push_back(scelte);
            return;
        }
        for(int i=pos;i<candidates.size();i++)
        {
            if(candidates[i]<=rim)
            {
                scelte.push_back(candidates[i]);
                back(i,scelte,rim-candidates[i],candidates,ris);
                scelte.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ris;
        if(target==0)
            return ris;
        vector<int> scelte;
        back(0,scelte,target,candidates,ris);
        return ris;
    }
};
