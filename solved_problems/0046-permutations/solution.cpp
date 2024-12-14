class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int> > ris;
        sort(nums.begin(),nums.end());
        do
        {
            ris.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return ris;
    }
};
