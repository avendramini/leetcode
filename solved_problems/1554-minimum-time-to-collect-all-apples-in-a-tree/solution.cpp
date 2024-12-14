class Solution {
public:
    
    int dfs(int pos,int p,vector<vector<int>>& edges, vector<bool>& hasApple)
    {
        int sum=0;
        for(auto x: edges[pos])
        {
            if(x!=p)
            {
                sum+=dfs(x,pos,edges,hasApple);
                hasApple[pos]=hasApple[pos] || hasApple[x];
                
                if(hasApple[x]){
                    cout<<pos<<" "<<x<<endl;
                    sum+=2;
                }
            }
        }
        return sum;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        vector<vector<int> > archi(n);
        for(int i=0;i<edges.size();i++)
        {
            archi[edges[i][0]].push_back(edges[i][1]);
            archi[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0,-1,archi,hasApple);
    }
};
