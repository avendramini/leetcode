class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        vector<int> b(26,0);
                if(s.size()!=t.size())
            return false;
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(v[i]!=b[i])
                return false;
        }
        return true;
    }
};

