class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,bool> used;
        if(t.size()!=s.size())
        return false;
        for(int i=0;i<s.size();i++)
        {
            if((m.count(s[i])>0&&m[s[i]]!=t[i])||(m.count(s[i])==0&&used.count(t[i])))
                return false;
            else if(m.count(s[i])==0)
            {
                used[t[i]]=true;
                m[s[i]]=t[i];
            }
        }
        return true;
    }
};
