class Solution {
public:
    bool back(int posx,int posy,int posw,string& word,vector<vector<bool> > & vis,vector<vector<char> >& board)
    {
        if(posw==word.size())
            return true;
        bool ok=false;
        int n=board.size();
        int m=board[0].size();
        for(int i=-1;i<=1;i+=2)
        {
            if(posx+i<n&&posx+i>=0&&!vis[posx+i][posy]&&board[posx+i][posy]==word[posw])
            {
                vis[posx+i][posy]=true;
                ok|=back(posx+i,posy,posw+1,word,vis,board);
                vis[posx+i][posy]=false;
            }
            if(posy+i<m&&posy+i>=0&&!vis[posx][posy+i]&&board[posx][posy+i]==word[posw])
            {
                vis[posx][posy+i]=true;
                ok|=back(posx,posy+i,posw+1,word,vis,board);
                vis[posx][posy+i]=false;
            }
            
        }
        return ok;

    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ok=false;
        vector<vector<bool> > vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(word[0]==board[i][j])
                {
                    vis[i][j]=true;
                    ok|=back(i,j,1,word,vis,board);
                    vis[i][j]=false;
                }
            }
        }
        
        return ok;
    }
};
