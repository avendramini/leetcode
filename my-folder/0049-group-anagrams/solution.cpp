class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string,vector<int> > m;
        for(int i=0;i<strs.size();i++)
        {
            string app=strs[i];
            sort(app.begin(),app.end());
            m[app].push_back(i);
        }
        int i=0;
        vector<vector<string> > v(m.size());
        for(auto x: m)
        {
            for(auto j :x.second)
                v[i].push_back(strs[j]);
            i++;
        }
        return v;
    }
};
