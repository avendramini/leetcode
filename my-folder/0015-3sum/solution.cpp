class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int> > ris;
        vector<int> vec;
        int n=nums.size();
        for(int i=0;i<n;i++)
            vec.push_back(nums[i]);
        sort( vec.begin(), vec.end() ); 
        n=vec.size();
        for(int i=0;i<n;i++)
        {
            int k=n-1;
            for(int j=i+1;j<k&&j<n;j++)
            {
                
                while(k>j&&vec[i]+vec[j]+vec[k]>0)
                {
                    k--;
                }
                if(vec[i]+vec[j]+vec[k]==0&&j<k){
                    vector<int> v={vec[i],vec[j],vec[k]};
                    ris.insert(v);
                }
            }

        }
        vector<vector<int>> ret;
        for(auto x: ris)
            ret.push_back(x);
        return ret;
    }
};
