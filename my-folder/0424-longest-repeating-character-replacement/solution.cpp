class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        vector<vector<int>> pos(26);
        for(int i=0;i<s.size();i++)
        {
            pos[s[i]-'A'].push_back(i);
        }
        int massimo=min(k,(int)s.size());
        for(int i=0;i<26;i++)
        {
            if(pos[i].size()==0)
                continue;
            if(pos[i].size()==1){
                massimo=max(massimo,k+1);
                continue;
            }

            int start=0;
            int end=0;
            int cont=0;
            int j=1;
            do
            {
                j=max(j,start+1);
                if(start>0)
                cont-=(pos[i][start]-pos[i][start-1]-1);
                cont=max(0,cont);
                cout<<start<<j<<endl;
                while(j<pos[i].size()&&cont+pos[i][j]-pos[i][j-1]-1<=k)
                {
                    end=j;
                    cont+=pos[i][j]-pos[i][j-1]-1;
                    j++;
                }
                massimo=max(pos[i][end]-pos[i][start]+1+(k-cont),massimo);
                start++;
            }while(start<pos[i].size()&&j<pos[i].size());
            
        }
        return min(massimo,(int)s.size());
    }
};
