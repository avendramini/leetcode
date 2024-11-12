class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        vector<pair<int,int> > v;
        for(auto x: items)
            v.push_back({x[0],x[1]});
        sort(v.begin(),v.end());
        vector<int> prefix(items.size());
        prefix[0]=v[0].second;
        for(int i=1;i<v.size();i++)
        {
            prefix[i]=max(prefix[i-1],v[i].second);
        }
        vector<int> ris;
        for(int i=0;i<queries.size();i++)
        {
            auto itr = std::lower_bound(v.begin(), v.end(), make_pair(queries[i], (int)1e9+1), 
                                        [](const pair<int, int>& a, const pair<int, int>& b) {
                                            if(a.first!=b.first)
                                            return a.first < b.first;
                                            return a.second<b.second;
                                        });
            if(itr==v.end())
            {
                ris.push_back(prefix[prefix.size()-1]);
            }
            else if(itr-v.begin()==0)
                ris.push_back(0);
            else
            ris.push_back(prefix[itr-v.begin()-1]);
        }
        return ris;
    }
};
