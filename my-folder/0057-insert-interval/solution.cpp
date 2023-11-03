class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ris;
        bool ok=true;
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][1]<newInterval[0])
                ris.push_back(intervals[i]);
            else if(intervals[i][0]>newInterval[1]){
                if(ok)
                {
                    ok=false;
                    ris.push_back(newInterval);
                }
                ris.push_back(intervals[i]);
            }
            else
            {
                newInterval[0]=min(intervals[i][0],newInterval[0]);
                newInterval[1]=max(intervals[i][1],newInterval[1]);
                while(i<intervals.size()&&newInterval[1]>=intervals[i][0])
                {
                    newInterval[1]=max(intervals[i][1],newInterval[1]);
                    i++;
                }
                i--;
                ris.push_back(newInterval);
                ok=false;
            }

        }
        if(ok){
            if(intervals.size()==0||intervals[intervals.size()-1][1]<newInterval[0])
            ris.push_back(newInterval);
            else
            {
                ris.insert(ris.begin(),newInterval);
            }
        }
        return ris;
    }
};
