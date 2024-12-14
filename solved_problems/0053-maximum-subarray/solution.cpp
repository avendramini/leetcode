class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int massimo=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]>0){
                sum+=nums[i];
                massimo=max(massimo,sum);
            }
            else
                sum=0;
            
            massimo=max(massimo,nums[i]);
        }
        return massimo;
    }
};
