class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int> > finale;
        int n=board.size();
        int m=board[0].size();
        finale.resize(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int tot=0;
                for(int ox=-1;ox<=1;ox++)
                {
                    for(int oy=-1;oy<=1;oy++)
                    {
                        if(ox==0&&oy==0)
                            continue;
                        if(i+ox>=0&&i+ox<n)
                        {
                            if(j+oy>=0&&j+oy<m)
                            {
                                if(board[i+ox][j+oy])
                                    tot++;
                            }
                        }
                    }
                }
                if(board[i][j]==0)
                {
                    if(tot==3)
                        finale[i][j]=1;
                    else
                        finale[i][j]=0;
                }
                else    
                {
                    if(tot<2||tot>3)
                        finale[i][j]=0;
                    else
                        finale[i][j]=1;

                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                board[i][j]=finale[i][j];
        }
    }
};
