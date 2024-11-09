class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int cont=0;
        map<int,int> f;
        vector<pair<int,int> > tot;        
        for(auto x: nums){
                f[x]++;
                cont=max(f[x],cont);
            tot.push_back({x,1});
        }
        if(k==0)
            return cont;
        
        
        for(auto x: nums)
        {
            tot.push_back({max(0,x-k),0});
            tot.push_back({min((int)1e9+1,x+k+1),2});
        }
        
        sort(tot.begin(),tot.end());
        int best=cont;
        int aperte=0;
        for(int i=0;i<tot.size();i++)
        {
            int att=tot[i].first;
            while(i<tot.size()&&tot[i].first==att)
                {
                    if(tot[i].second==0)
                    {
                        aperte++;
                    }
                    else if(tot[i].second==2)
                        aperte--;
                    i++;
                }
            i--;
                
            if(aperte-f[att]<=numOperations)
            {
                best=max(best,aperte);
            }
            else
                best=max(best,numOperations+f[att]);
        }
        
        return best;
    }
};
