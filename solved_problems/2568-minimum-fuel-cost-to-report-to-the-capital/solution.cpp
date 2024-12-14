class Solution {
public:
    vector<vector<pair<int,int> >> adj;
    long long toti=0;
    int seatsi=0;
    int dfs(int pos,int p)
    {
        int tot=1;
        for(int i=0;i<adj[pos].size();i++)
        {
            if(adj[pos][i].first!=p)
            {
                int att=dfs(adj[pos][i].first,pos);
                tot+=att;
                adj[pos][i].second=att;
                toti+=ceil((att+0.0)/seatsi);
            }
        }
        
        return tot;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        seatsi=seats;

        adj.resize(roads.size()+1);
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back({roads[i][1],0});
            adj[roads[i][1]].push_back({roads[i][0],0});
        }
        dfs(0,-1);

        return toti;

    }
};
