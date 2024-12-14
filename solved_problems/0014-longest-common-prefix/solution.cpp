class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int limite=strs[0].size();
        int n=strs.size();
        for(int i=1;i<n;i++)
        {
            limite=min(limite,(int)strs[i].size());
            for(int j=0;j<limite;j++)
            {
                if(strs[0][j]!=strs[i][j])
                {
                    limite=j;
                    break;
                }
            }
        }
        string s="";
        for(int i=0;i<limite;i++)
        {
            s+=strs[0][i];
        }
        return s;
    }
};
