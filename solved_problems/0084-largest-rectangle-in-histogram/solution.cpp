class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<pair<int,int> > s;
        int massimo=0;
        int minimo=1e9;
        vector<int> risp(heights.size(),0);
        for(int i=0;i<heights.size();i++)
        {
            minimo=min(minimo,heights[i]);
            massimo=max(massimo,heights[i]);
            while(s.size()>0&&s.top().first>heights[i])
            {
                
                massimo=max(massimo,(i-s.top().second)*s.top().first);
                risp[s.top().second]+=(i-s.top().second-1)*s.top().first;
                s.pop();
            }
            s.push({heights[i],i});
        }
        while(s.size()>0)
        {
            massimo=max(massimo,((int)heights.size()-s.top().second)*s.top().first);
            risp[s.top().second]+=((int)heights.size()-1-s.top().second)*s.top().first;
            s.pop();
        }

               
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(s.size()>0&&s.top().first>heights[i])
            {
                cout<<s.top().first<<" "<<s.top().second<<" "<<i<<endl;
                massimo=max(massimo,(s.top().second-i)*s.top().first);
                risp[s.top().second]+=(s.top().second-i)*s.top().first;
                massimo=max(massimo,risp[s.top().second]);
                s.pop();
            }
            s.push({heights[i],i});
        }
        while(s.size()>0)
        {
            massimo=max(massimo,(s.top().second+1)*s.top().first);
            risp[s.top().second]+=(s.top().second+1)*s.top().first;
             massimo=max(massimo,risp[s.top().second]);
            s.pop();
        }
        massimo=max(minimo*(int)heights.size(),massimo);
        
        return massimo;
    }
};
