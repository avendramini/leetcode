class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        bool pres[201]={false};
        for(int i=0;i<nums.size();i++)
        {
            pres[nums[i]+100]=true;
            
        }
        for(int i=0;i<201;i++)
        {
            if(pres[i]){
            nums[k]=i-100;
            k++;
            }
        }
        return k;
    }
};
