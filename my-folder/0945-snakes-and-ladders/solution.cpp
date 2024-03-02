class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int>vett;
        int n=board.size();
        bool destra=true;
        int x=n-1;
        int y=0;
        while(vett.size()<n*n)
        {
            vett.push_back(board[x][y]);
            if(destra)
            y++;
            else
            {
                y--;
            }
            if(y==n&&destra)
            {
                y=n-1;
                x--;
                destra=!destra;
            }
            else if(y==-1&&!destra)
            {
                y=0;
                x--;
                destra=!destra;
            }
        }
        queue<int> q;
        vector<bool> vis(n*n,false);
        q.push(0);
        int tot=1;
        int cont=0;
        while(q.size()>0)
        {
            int pos=q.front();
            q.pop();
            tot--;
            if(vis[pos]){
                if(tot==0){
                tot=q.size();
                cont++;
                }
                continue;
            }
            vis[pos]=true;
            cout<<cont<<" "<<pos<<endl;
            if(pos==n*n-1)
            {
                return cont;
            }
            for(int i=1;pos+i<n*n&&i<=6;i++)
            {
                if(vett[pos+i]==-1&&!vis[pos+i])
                    q.push(pos+i);
                else if(vett[pos+i]!=-1&&!vis[vett[pos+i]-1])
                    q.push(vett[pos+i]-1);
            }
                        if(tot==0)
            {
                tot=q.size();
                cont++;
            }
            
        }
        return -1;


    }
};
