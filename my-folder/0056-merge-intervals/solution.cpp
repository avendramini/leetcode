class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ris;
                std::sort(intervals.begin(), intervals.end(),
                [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
        });
        for(int i=0;i<intervals.size();i++)
        {
            int end=intervals[i][1];
            int j=i+1;
            while(j<intervals.size()&&intervals[j][0]<=end)
            {
                end=max(end,intervals[j][1]);
                j++;
            }
            ris.push_back({intervals[i][0],end});
            i=j-1;
        }
        return ris;
    }
};
