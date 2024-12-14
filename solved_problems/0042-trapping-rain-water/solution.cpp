class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<pair<int,int> > s;
        stack<pair<int,int> > p;
        vector<int> tot(n,0);
        s.push({height[0],0});
        vector<int> next(height.size(),-1);
        vector<int> prev(height.size(),-1);
        for(int i=1;i<height.size();i++)
        {
            if(s.size()==0)
            {
                s.push({height[i],i});
                continue;
            }
            while(s.size()>0&&s.top().first<=height[i])
            {
                int pos=s.top().second;
                next[pos]=i;
                s.pop();
            }
            s.push({height[i],i});

       }

        p.push({height[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            if(p.size()==0)
            {
                p.push({height[i],i});
                continue;
            }
            while(p.size()>0&&p.top().first<=height[i])
            {
                int pos=p.top().second;
                prev[pos]=i;
                p.pop();
            }
            p.push({height[i],i});
        }
       int ris=0;
        for(int i=0;i<height.size();i++)
        {
            if(next[i]==-1)
                continue;
            int j=i;
            while(j!=next[i])
            {
                tot[j]=height[i]-height[j];
                ris+=height[i]-height[j];
                j++;
            }
            i=j-1;
        }

        for(int i=n-1;i>=0;i--)
        {
            if(prev[i]==-1)
                continue;
            if(height[prev[i]]==height[i])
            {                i=prev[i]+1;
                continue;
            }
            int j=i;
            while(j!=prev[i])
            {
                tot[j]=max(tot[j],height[i]-height[j]);
                ris+=height[i]-height[j];
                j--;
            }
            i=j+1;
        }
        ris=0;
        for(int i=0;i<n;i++)
            ris+=tot[i];
        return ris;
    }
};
