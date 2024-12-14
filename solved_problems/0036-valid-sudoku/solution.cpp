class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            bitset<9> pres(0);
            bitset<9> presCol(0);
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'0';
                    if(pres[num]==1)
                        return false;
                    pres[num]=1;
                }
                if(board[j][i]!='.')
                {
                    int num=board[j][i]-'0';
                    if(presCol[num]==1)
                        return false;
                    presCol[num]=1;
                }
            }
        }
        for(int startx=0;startx<9;startx+=3)
        {
            for(int starty=0;starty<9;starty+=3)
            {
                bitset<9> pres(0);
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(board[startx+i][starty+j]!='.')
                        {
                            int num=board[startx+i][starty+j]-'0';
                            if(pres[num])   
                                return false;
                            pres[num]=1;
                        }
                    }
                }
            }
        }
        return true;
    }
};
