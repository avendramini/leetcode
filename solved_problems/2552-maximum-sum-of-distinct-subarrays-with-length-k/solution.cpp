class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int,int> m;
        bool ok=true;
        long long sum=0;
        unordered_map<int,bool> doppio;
        int doppi=0;
        for(int i=0;i<k;i++){
            m[nums[i]]++;
            sum+=nums[i];
            if(m[nums[i]]>1){
                ok=false;
                doppio[nums[i]]=true;
                doppi++;
            }
        }
        long long ris=0;
        if(ok)
            ris=sum;
        for(int i=1;i<=n-k;i++)
        {
            sum-=nums[i-1];
            m[nums[i-1]]--;
            if(doppio[nums[i-1]])
            {
                if(m[nums[i-1]]==1){
                    doppio[nums[i-1]]=false;
                }
                doppi--;
            }
            if(doppi==0)
                ok=true;
            sum+=nums[i+k-1];
            m[nums[i+k-1]]++;
            if(m[nums[i+k-1]]>1)
            {
                doppi++;
                doppio[nums[i+k-1]]=true;
                ok=false;
            }
            if(ok)
            ris=max(ris,sum);
            
        }
        return ris;
        
    }
};
