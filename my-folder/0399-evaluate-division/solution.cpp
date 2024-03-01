class Solution {
public:
    map<string,int> corr;
    map<pair<int,int>,bool> vis;
    int vsopra,vsotto;
    double rico(int sopra,int sotto,int passi,double ris,  vector<vector<string>>& equations,vector<double>& values)
    {
        vis[{sopra,sotto}]=true;
        if(sopra==vsopra&&sotto==vsotto)
            return ris;
        if(passi==equations.size())
            return -1;
        double poss=-1;
        for(int i=0;i<equations.size();i++)
        {
            vector<string> x=equations[i];
            if(corr[x[0]]==sotto&&!vis[{sopra,corr[x[1]]}])
                poss=max(poss,rico(sopra,corr[x[1]],passi+1,ris*values[i],equations,values));
            if(corr[x[1]]==sotto&&!vis[{sopra,corr[x[0]]}])
                poss=max(poss,rico(sopra,corr[x[0]],passi+1,ris/values[i],equations,values));
        }
        return poss;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        vector<double> ris;
        int cont=0;
        for(auto x: equations)
        {
            if(!corr.count(x[0]))
            {
                corr[x[0]]=cont;
                cont++;
            }
            if(!corr.count(x[1]))
            {
                corr[x[1]]=cont;
                cont++;
            }
        }
        for(auto x: queries)
        {
            
            if(!corr.count(x[0])||!corr.count(x[1]))
            {
                ris.push_back(-1);
                continue;
            }
            vsopra=corr[x[0]];
            vsotto=corr[x[1]];
            double app=-1;
            for(int i=0;i<equations.size();i++)
            {
                vis.clear();
                if(corr[equations[i][0]]==vsopra)
                {
                    app=max(app,rico(vsopra,corr[equations[i][1]],0,values[i],equations,values));
                    cout<<equations[i][0]<<" "<<equations[i][1]<<" "<<app<<endl;
                }
                if(corr[equations[i][1]]==vsopra)
                {
                     app=max(app,rico(vsopra,corr[equations[i][0]],0,1.0/values[i],equations,values));
                }
            }
            ris.push_back(app);
        }
        return ris;


    }
};
