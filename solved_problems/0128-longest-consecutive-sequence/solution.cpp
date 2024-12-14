class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=true;
        
        int last=-1e9;
        int att=0;
        int j=0;
        int massimo=0;
        for(auto x: m)
        {
            //cout<<x.first<<" "<<att<<endl;
            if(x.first==last+1||j==0)
            {
                att++;
                last=x.first;
                massimo=max(massimo,att);
            }
            else
            {
                last=x.first;
                att=1;
                j=0;
            }
            j++;
        }
        return massimo;
    }
};
