class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        string app=s1;
        s1=s2;
        s2=app;
        if(s2.size()>s1.size())
            return false;
        vector<int> occ(26,0);
        vector<int> occVero(26,0);
        for(int i=0;i<s2.size();i++)
        {
            occ[s1[i]-'a']++;
            occVero[s2[i]-'a']++;
        }
        bool ok=true;
        for(int i=0;i<26;i++)
        {
            if(occ[i]!=occVero[i])
                ok=false;
        }
        if(ok)
            return true;
        for(int i=s2.size();i<s1.size();i++)
        {
            occ[s1[i-s2.size()]-'a']--;
            occ[s1[i]-'a']++;
            bool oki=true;
            for(int j=0;j<26;j++)
            {
                if(occ[j]!=occVero[j])
                    oki=false;
            }
            if(oki)
                return true;
            
        }
        return false;

    }
};
