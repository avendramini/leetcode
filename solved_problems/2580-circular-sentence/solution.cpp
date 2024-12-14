class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        vector<string> l;
        string s="";
        for(auto x: sentence)
        {
            if(x==' ')
            {
                l.push_back(s);
                s="";
            }
            else
            s+=x;
        }
        l.push_back(s);
        for(int i=0;i<l.size()-1;i++)
        {
            if(l[i][l[i].size()-1]!=l[i+1][0])
                return false;
        }
        if(l[0][0]==l[l.size()-1][l[l.size()-1].size()-1])
            return true;
        return false;
    }
};
