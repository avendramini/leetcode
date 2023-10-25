class Solution {
public:
    vector<int> num;
    vector<bool> vis;
    vector<vector<int> >adj;
    vector<vector<int> > div;
    Solution()
    {
        num.assign(26,-1);
        vis.assign(26,false);
        adj.resize(26);
        div.resize(26);
    }
    bool equalizza(int pos,int colore)
    {
        bool ok =true;
        if(num[pos]!=-1&&num[pos]!=colore)
            return false;
        num[pos]=colore;
        vis[pos]=true;
        for(auto x: adj[pos])
        {
            if(!vis[x])
                ok=ok&equalizza(x,colore);
        }
        return ok;
    }
    bool equationsPossible(vector<string>& equations) 
    {
        for(int i=0;i<equations.size();i++)
        {
            int a=equations[i][0]-'a';
            int b=equations[i][3]-'a';
            if(equations[i][1]=='!')
            {
                div[a].push_back(b);
                div[b].push_back(a);
            }
            else
            {
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }

        int col=0;
        for(int i=0;i<26;i++)
        {
            if(!vis[i])
            {
                equalizza(i,col);
                col++;
            }
        }
        bool ok=true;
        for(int i=0;i<26;i++)
        {
            for(auto x: div[i])
            {
                if(num[x]==num[i])
                {
                    ok=false;
                }
            }
        }
        return ok;
    }
};
