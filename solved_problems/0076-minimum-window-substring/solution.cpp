class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> occ;
        for(int i=0;i<t.size();i++)
            occ[t[i]]++;
        
        if(t.size()>s.size())
            return "";
        int left=0;
        int right=0;
        int risr=-1;
        int risl=-1;
        unordered_map<char,int>  occ_att;
        occ_att[s[0]]++;
        while(left<s.size()&&right<s.size())
        {
            bool ok=true;
            for(auto x: occ)
            {
                if(occ_att[x.first]<x.second)
                    ok=false;
            }
            if(ok)
            {
                if((right-left+1)<(risr-risl+1)||risr==-1)
                    {
                        risr=right;
                        risl=left;
                    }
                occ_att[s[left]]--;
                left++;
                if(left>right)
                {
                    return s.substr(risl,risr-risl+1);
                }
            }
            else{

                right++;
                if(right<s.size())
                    {
                        occ_att[s[right]]++;
                    }
            }
        }
        if(risl==-1)
            return "";
        return s.substr(risl,risr-risl+1);
    }
};
