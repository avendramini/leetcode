class Solution {
public:
    vector<vector<string> > ris;
    vector<vector<int> > adj;
    vector<bool> vis;
    
    void dfs(int pos,int posRis,vector<vector<string>>& accounts)
    {
        vis[pos]=true;
        for(int j=1;j<accounts[pos].size();j++)
        {
            ris[posRis].push_back(accounts[pos][j]);
        }
        for(auto x: adj[pos])
        {
            if(!vis[x])
                dfs(x,posRis,accounts);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        map<string,int> m;
        adj.resize(accounts.size());
        vis.assign(accounts.size(),false);
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(m.count(accounts[i][j]))
                {
                    if(accounts[i][0]==accounts[m[accounts[i][j]]][0]){
                        adj[i].push_back(m[accounts[i][j]]);
                        adj[m[accounts[i][j]]].push_back(i);
                    }
                }
                m[accounts[i][j]]=i;
            }
        }
        for(int i=0;i<accounts.size();i++)
        {
            if(!vis[i])
            {
                ris.push_back({accounts[i][0]});
                dfs(i,ris.size()-1,accounts);
            }
        }
        for(int i=0;i<ris.size();i++)
        {
            sort(ris[i].begin()+1,ris[i].end());
            ris[i].erase( unique( ris[i].begin()+1, ris[i].end() ), ris[i].end() );
        }
        return ris;
    }
};
