class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        int cont=0;
        int max=0;
        for(auto x: m)
        {
            if(x.second>cont)
            {
                cont=x.second;
                max=x.first;
            }
        }
        return max;
    }
};
