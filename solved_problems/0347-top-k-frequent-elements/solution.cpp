class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto x: nums)
            m[x]++;
        
        vector<pair<int,int> > v;
        for(auto x: m)
            v.push_back({x.second,x.first});
        sort(v.begin(),v.end());
        vector<int> ris;
        for(int i=0;i<k;i++)
        {   
            ris.push_back(v[v.size()-i-1].second);
        }
        return ris;
    }
};
