class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int scelti=0;
        for(int i=0;i<n;i++)
        {
            nums[scelti]=nums[i];
            scelti++;
            int j=i+1;
            int cont=1;
            while(j<n&&nums[j]==nums[i])
            {
                cont++;
                if(cont==2)
                {
                    nums[scelti]=nums[j];
                    scelti++;
                }
                j++;
            }
            i=j-1;
        }
        return scelti;
    }
};
