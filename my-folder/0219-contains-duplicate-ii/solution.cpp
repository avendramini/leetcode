class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,bool> m;
        for(int i=0;i<nums.size()&&i<=k;i++)
        {
            if(m[nums[i]])
                return true;
            m[nums[i]]=true;
        }
        for(int i=k+1;i<nums.size();i++)
        {
            m[nums[i-k-1]]=false;
            if(m[nums[i]])
                return true;
            m[nums[i]]=true;
        }
        return false;
    }
};
