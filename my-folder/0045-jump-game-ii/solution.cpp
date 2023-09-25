class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        int tot=0;
        int salti=0;
        int pres=1;
        while(q.size()>0)
        {
            int att=q.front();
            q.pop();
            if(att==n-1)
                break;
            pres--;
            for(int i=att+1;i<n&&i<=att+nums[att];i++)
            {
                if(!vis[i]){
                q.push(i);
                vis[i]=true;
                }
            }
            if(pres==0)
            {
                salti++;
                pres=q.size();
            }
        }
        return salti;

    }
};
