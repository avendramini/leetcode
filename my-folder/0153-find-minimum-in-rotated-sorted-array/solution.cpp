class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int ans=1e9;
        while(l<=h)
        {
            int mid=(l+h)/2;
            ans=min(ans,nums[mid]);
            if(nums[l]<=nums[h]){
                ans=min(ans,nums[l]);
                break;
            }
            else if(nums[l]<=nums[mid])
                l=mid+1;
            else
            h=mid-1;
        }
        return ans;
    }
};
