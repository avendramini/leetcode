class Solution {
public:
    int rico(int riga,vector<vector<bool> > & mappa)
    {
        if(riga==mappa.size())
            return 1;
        int tot=0;
        for(int i=0;i<mappa.size();i++)
        {
            bool ok=true;
            for(int j=0;j<mappa.size();j++)
            {
                if(mappa[j][i])
                    ok=false;

                if(riga-j>=0&&i-j>=0&&mappa[riga-j][i-j])
                    ok=false;
                if(riga+j<mappa.size()&&i+j<mappa.size()&&mappa[riga+j][i+j])
                    ok=false;
                if(riga+j<mappa.size()&&i-j>=0&&mappa[riga+j][i-j])
                    ok=false;
                if(riga-j>=0&&i+j<mappa.size()&&mappa[riga-j][i+j])
                    ok=false;
            }
            if(ok){
                mappa[riga][i]=true;
                tot+=rico(riga+1,mappa);
                mappa[riga][i]=false;
            }

        }
        return tot;


    }
    int totalNQueens(int n) {
        vector<vector<bool> > mappa(n,vector<bool>(n,false));
        return rico(0,mappa);
    }
};
