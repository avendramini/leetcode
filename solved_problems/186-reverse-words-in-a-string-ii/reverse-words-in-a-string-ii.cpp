class Solution {
public:
    void reverseWords(vector<char>& s) {
        vector<string> words;
        string att="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' '){
                words.push_back(att);
                att="";
            }
            else
            {
                att+=s[i];
            }
        }
        words.push_back(att);
        vector<char> res;
        for(int i=words.size()-1;i>=0;i--)
        {
            for(int j=0;j<words[i].size();j++)
            {
                res.push_back(words[i][j]);
            }
            if(i!=0)
            {
                res.push_back(' ');
            }
        }
        s=res;
    }
};