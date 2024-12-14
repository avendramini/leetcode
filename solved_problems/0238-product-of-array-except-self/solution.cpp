class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
       vector<int> prefix(n+1);
       vector<int> suffix(n+1);
       prefix[0]=1;
       suffix[n]=1;
       for(int i=1;i<=n;i++)
       {
           prefix[i]=prefix[i-1]*nums[i-1];
           suffix[n-i]=suffix[n-i+1]*nums[n-i];
       }
       vector<int> ris(n);
       for(int i=0;i<n;i++)
       {
           ris[i]=prefix[i]*suffix[i+1];
       }
       return ris;
       

    }
};
