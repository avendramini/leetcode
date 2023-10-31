class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string,char> m;
        map<char,string> minv;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            string app="";
            while(i<s.size()&&s[i]!=' ')
                {
                    app+=s[i];
                    i++;
                }
            cout<<app<<endl;
            if(m.count(app)>0&&m[app]!=pattern[j])
                return false;
            else if(minv.count(pattern[j])>0&&minv[pattern[j]]!=app)
                return false;
            else{
            m[app]=pattern[j];
            minv[pattern[j]]=app;
            }
            j++;
        }
        if(j!=pattern.size())
        return false;
        return true;
    }
};
