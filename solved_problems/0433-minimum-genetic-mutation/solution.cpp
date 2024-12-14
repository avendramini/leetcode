class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        map<string,bool> vis;
        q.push(startGene);
        int tot=1;
        int cont=0;
        while(q.size()>0)
        {
            string att=q.front();
            q.pop();
            tot--;
            if(vis[att])
            {
                if(tot==0)
                {
                    tot=q.size();
                    cont++;
                }
                continue;

            }
            vis[att]=true;
            if(att==endGene)
                return cont;
            for(auto x: bank)
            {
                int diff=0;
                for(int i=0;i<x.size();i++)
                {
                    if(x[i]!=att[i])
                        diff++;
                }
                if(diff==1&&!vis[x])
                {
                    q.push(x);
                }
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
