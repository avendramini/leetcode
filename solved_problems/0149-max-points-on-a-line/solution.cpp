class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        map<pair<double,double>, set<pair<int,int> > > ma;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double m=-1e9;
                double q=-1;
                if(points[i][0]!=points[j][0]){
                m=((double)points[i][1]-points[j][1])/((double)points[i][0]-points[j][0]);
                q=points[i][1]-m*points[i][0];
                }
                else
                {
                    q=points[i][0];
                }
                ma[{m,q}].insert({points[i][0],points[i][1]});
                ma[{m,q}].insert({points[j][0],points[j][1]});
            }
        }
        for(auto x :ma)
        {
            cout<<x.first.first<<" "<<x.first.second<<endl;
            for(auto k: x.second){
            cout<<k.first<<"-"<<k.second<<" ";
            }
            cout<<endl;
            cout<<endl;
        }
        int massimo=1;
        for(auto x: ma)
            massimo=max(massimo,(int)x.second.size());
        return massimo;
    }
};
