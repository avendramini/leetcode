class Solution {
public:
    bool isPalindrome(string s) {

        string p;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='A'&&s[i]<='Z'))
            {
                p+=s[i]-'A'+'a';
            }
            else if((s[i]>='a'&&s[i]<='z'))
            {
                p+=s[i];
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                p+=s[i];
            }
                
        }
        for(int i=0;i<p.size();i++)
        {
            if(p[i]!=p[p.size()-1-i])
            return false;
        }
        return true;
    }
};
