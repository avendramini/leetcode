class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ris(temperatures.size()); 
        stack<pair<int,int> > s;
        ris[ris.size()-1]=0;
        s.push({temperatures[ris.size()-1],ris.size()-1});
        int n=ris.size();
        for(int i=n-2;i>=0;i--)
        {
            if(temperatures[i]<temperatures[i+1])
                ris[i]=1;
            else
            {
                do
                {
                    pair<int,int> x=s.top();
                    if(x.first>temperatures[i])
                    {
                        ris[i]=x.second-i;
                        break;
                    }
                    else
                    s.pop();
                }while(s.size()>0);
            }
            s.push({temperatures[i],i});
        }
        return ris;
    }
};
