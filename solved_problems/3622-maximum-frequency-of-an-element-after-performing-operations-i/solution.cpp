class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int cont=0;
        map<int,int> f;
        for(auto x: nums){
                f[x]++;
                cont=max(f[x],cont);
        }
        if(k==0)
            return cont;
        
        vector<pair<int,int> > tot;
        for(auto x: nums)
        {
            tot.push_back({max(0,x-k),0});
            tot.push_back({min((int)1e5+1,x+k+1),1});
        }
        sort(tot.begin(),tot.end());
        int att=tot[0].first-1;
        int i=0;
        int best=cont;
        int aperte=0;
        while(i<tot.size())
        {
            att++;
            cout<<att<<" "<<i<<endl;
            while(i<tot.size()&&tot[i].first==att)
                {
                    if(tot[i].second==0)
                    {
                        aperte++;
                    }
                    else
                        aperte--;
        
                    i++;
                }
                
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
