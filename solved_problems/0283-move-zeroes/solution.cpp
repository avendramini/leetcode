class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i=0;
        int j=0;
        while(j<nums.size()&&nums[j]!=0)
        j++;
        while(i<nums.size()&&j<nums.size())
        {
            while(j<nums.size()&&nums[j]==0)
            {
                j++;
            }

            if(i<nums.size()&&j<nums.size()&&i<j&&nums[i]==0)
            swap(nums[i],nums[j]);
            i++;
        }
    }
};
