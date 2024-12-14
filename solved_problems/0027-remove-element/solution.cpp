class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int tolti=0;
        for(int i=0;i<nums.size()-tolti;i++)
        {
            if(nums[i]==val){
            swap(nums[i],nums[nums.size()-1-tolti]);
            i--;
            tolti++;
            }
        }
        return nums.size()-tolti;
    }
};
