class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int> > att(n);
        for(int i=0;i<n;i++)
        {
            att[i].first=nums[i];
            att[i].second=i;
        }
        sort(att.begin(),att.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            int sum=att[i].first+att[j].first;
            if(sum==target)
            {
                return {att[i].second,att[j].second};
            }
            if(sum>target)
                j--;
            else
                i++;
        }
        return {0,0};
    }
};
