class Solution {
public:
    vector<vector<int> > ris;
    void rico(int pos,vector<int> &nums,vector<int>& att)
    {
        if(pos==nums.size()){
            ris.push_back(att);
            return;
        }
        rico(pos+1,nums,att);
        att.push_back(nums[pos]);
        rico(pos+1,nums,att);
        att.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> att;
        rico(0,nums,att);
        return ris;
    }
};
