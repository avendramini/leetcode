class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>ans[ans.size()-1])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int it=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[it]=nums[i];
            }
        }
        return ans.size();
    }
};
