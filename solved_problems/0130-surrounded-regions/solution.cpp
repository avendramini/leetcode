class Solution {
public:
    vector<vector<bool>> vis;
    int n,m;
    void dfs(int posx,int posy,vector<vector<char>>& board)
    {
        vis[posx][posy]=true;
        for(int i=-1;i<2;i+=2)
        {
            if(posx+i>=0&&posx+i<n&&!vis[posx+i][posy]&&board[posx+i][posy]=='O')
            {
                dfs(posx+i,posy,board);
            }
            if(posy+i>=0&&posy+i<m&&!vis[posx][posy+i]&&board[posx][posy+i]=='O')
            {
                dfs(posx,posy+i,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vis.assign(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O'&&!vis[i][0])
                dfs(i,0,board);
            if(board[i][m-1]=='O'&&!vis[i][m-1])
                dfs(i,m-1,board);
        }
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O'&&!vis[0][i])
                dfs(0,i,board);
            if(board[n-1][i]=='O'&&!vis[n-1][i])
                dfs(n-1,i,board);
        }
        for(int i=0;i<n;i++ )
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};
