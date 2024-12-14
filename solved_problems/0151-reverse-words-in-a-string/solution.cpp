class Solution {
public:
    string reverseWords(string s) {
        vector<string> tot;
        int i=0;
        while(s[i]==' ')
        i++;
        for(;i<s.size();i++)
        {
            string parola="";
            while(i<s.size()&&s[i]!=' ')
            {
                parola+=s[i];
                i++;
            }
            tot.push_back(parola);
            while(i<s.size()&&s[i]==' ')
                i++;
            i=i-1;
        }
        string ris="";
        for(int i=tot.size()-1;i>=0;i--)
        {
            ris+=tot[i];
            if(i!=0)
            ris+=' ';
        }
        return ris;

    }
};
