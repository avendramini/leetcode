class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size());
        for(int i=0;i<n;i++)
        {
            if(i-2>=0)
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
            else if(i-1>=0)
            dp[i]=max(dp[i-1],nums[i]);
            else if(i==0)
            dp[i]=nums[i];
        }
        return dp[n-1];
    }
};
