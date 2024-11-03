class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        for(int i=0;i<s.size();i++)
        {
            bool ok=true;
            for(int j=0;j<s.size();j++)
            {
                if(s[(i+j)%s.size()]!=goal[j])
                    ok=false;
            }
            if(ok)
                return true;
        }
        return false;
    }
};
