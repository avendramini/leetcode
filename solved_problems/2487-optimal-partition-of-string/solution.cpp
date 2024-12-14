class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,bool> m;
        int cont=1;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]])
            {
                cont++;
                for(auto x: m)
                    m[x.first]=false;
            }
            m[s[i]]=true;
        }
        return cont;
    }
};
