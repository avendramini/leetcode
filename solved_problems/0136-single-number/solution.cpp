class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int att=0;
       for(int i=0;i<nums.size();i++)
       {
           att^=nums[i];
       }
       return att;
    }
};
