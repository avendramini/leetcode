class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int tot=0;
        vector<pair<int,int> > v;
        
        for(int i=0;i<points.size();i++)
        {
            v.push_back({points[i][0],points[i][1]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            tot++;
            int sinistra=v[i].first;
            int destra=v[i].second;
            while(i+1<v.size()&&v[i+1].first<=destra&&sinistra<=destra)
            {
                sinistra=v[i+1].first;
                destra=min(destra,v[i+1].second);
                i++;
            }
        }
        return tot;
    }
};
