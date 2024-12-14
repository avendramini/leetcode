class Solution {
public:
    vector<vector<int> > pal;
    string s2;
    bool rico(int pos,int pos2)
    {
        if(pal[pos][pos2]!=-1)
            return pal[pos][pos2];
        if(pos>=pos2)
        {
            return pal[pos][pos2]=true;
        }
        
        
        bool ok=false;
        if(s2[pos]==s2[pos2])
        {
            ok|=rico(pos+1,pos2-1);
        }
        return pal[pos][pos2]=ok;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        s2=s;
        pal.assign(n,vector<int>(n,-1));
        rico(0,n-1);
        int massimo=0;
        int a,b;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                bool ok=true;
                ok=rico(i,j);
                if(ok)
                {
                    if(j-i+1>massimo)
                    {
                        massimo=j-i+1;
                        a=i;
                        b=j;
                    }
                }
            }
        }
        string ris="";
        for(int i=a;i<=b;i++)
            ris+=s[i];
        return ris;
    }
};
