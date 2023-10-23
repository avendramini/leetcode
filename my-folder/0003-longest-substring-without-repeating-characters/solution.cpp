class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int massimo=0;
        map<char,int> pos;
        int primo=-1;
        for(int i=0;i<s.size();i++)
        {
            auto it=st.find(s[i]);
            if(it==st.end())
            {
                st.insert(s[i]);
                pos[s[i]]=i;
                if(st.size()==1)
                    primo=i;
            }
            else
            {
                for(int j=primo;j<=pos[s[i]];j++)
                {
                    st.erase(s[j]);
                }
                primo=pos[s[i]]+1;
                pos[s[i]]=i;
                st.insert(s[i]);
            }
            massimo=max(massimo,(int)st.size());
        }
        return massimo;
    }
};
