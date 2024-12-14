class Solution {
public:
set<vector<int> > ris;
    void rico(int pos,vector<int> &nums,vector<int>& att)
    {
        if(pos==nums.size()){
            vector<int> copia=att;
            sort(copia.begin(),copia.end());
            ris.insert(copia);
            return;
        }
        rico(pos+1,nums,att);
        att.push_back(nums[pos]);
        rico(pos+1,nums,att);
        att.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> att;
        rico(0,nums,att);
        vector<vector<int> > ok;
        for(auto x: ris)
            ok.push_back(x);
        return ok;
    }
};
