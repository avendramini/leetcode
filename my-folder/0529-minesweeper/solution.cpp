class Solution {
public:

    void dfs(int x,int y,vector<vector<char>>& board)
    {
        if(board[x][y]!='E')
            return;
        int cont=0;
        for(int k=-1;k<=1;k++)
        {
            for(int l=-1;l<=1;l++)
            {
                if(min(x+k,y+l)>=0&&x+k<board.size()&&y+l<board[0].size() && (board[x+k][y+l]=='M'||board[x+k][y+l]=='X'))
                {
                    cont++;

                }
            }
        }
        if(cont!=0)
         board[x][y]=cont+'0';
        else
        {
            board[x][y]='B';
                    for(int k=-1;k<=1;k++)
        {
            for(int l=-1;l<=1;l++)
            {
                if(min(x+k,y+l)>=0&&x+k<board.size()&&y+l<board[0].size() && board[x+k][y+l]=='E')
                {
                    dfs(x+k,y+l,board);

                }
            }
        }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M')
        {
            board[click[0]][click[1]]='X';
            return board;
        }
        dfs(click[0],click[1],board);
        return board;
    }
};
