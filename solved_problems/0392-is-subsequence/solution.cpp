class Solution {
public:

    bool isSubsequence(string s, string t) {
        int pos=0;
        for(int i=0;i<t.size();i++)
        {
            if(pos==s.size())
            return true;
            if(s[pos]==t[i])
            {
                pos++;
            }
        }
        if(pos==s.size())
        return true;
        return false;
    }
};
