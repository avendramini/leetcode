class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> m;
        for(auto x: answers)
        {
            if(!m.count(x))
                m[x]=0;
            m[x]+=1;
        }
        int tot=0;
        for(auto x: m)
        {
            tot+=ceil((x.second+0.0)/(x.first+1.0))*(x.first+1);
        }
        return tot;

    }
};