class Solution {
public:
    int n,m;
    vector<vector<bool> > vis;
    void dfs(int x,int y)
    {
        
        vis[x][y]=true;
        for(int i=-1;i<=1;i+=2)
        {
            if(x+i<n&&x+i>=0&&!vis[x+i][y])
                dfs(x+i,y);
            if(y+i<m&&y+i>=0&&!vis[x][y+i])
                dfs(x,y+i);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vis.assign(n,vector<bool>(m,false));
        int cont=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!='1') 
                vis[i][j]=true;
            }

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&&!vis[i][j]) 
                dfs(i,j),cont++;
            }

        }
        return cont;
    }
};
