class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int att=w;
        vector<pair<int,int> > prog;
        int n=profits.size();
        for(int i=0;i<n;i++)
        {
            prog.push_back({capital[i],profits[i]});
        }
        sort(prog.begin(),prog.end());
        priority_queue<int > q;
        int indice=0;
        int presi=0;
        for(int i=0;i<n;i++)
        {
            if(prog[i].first<=w)
                q.push(prog[i].second);
            else
                break;
            indice=i;
        }
        indice++;
        while(q.size()>0&&presi<k)
        {
            int primo=q.top();
            q.pop();
            att+=primo;

            while(indice<n&&prog[indice].first<=att)
            {
                q.push(prog[indice].second);
                indice++;
            }
            presi++;
        }

        return att;
    }
};
