class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ris(2*nums.size());
        for(int i=0;i<nums.size();i++)
        {
            ris[i]=nums[i];
            ris[i+nums.size()]=nums[i];
        }
        return ris;
    }
};
