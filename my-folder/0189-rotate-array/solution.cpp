class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ris(n);
        for(int i=0;i<n;i++)
        {
            ris[(i+k)%n]=nums[i];
        }
        for(int i=0;i<n;i++)
            nums[i]=ris[i];
        
    }
};
