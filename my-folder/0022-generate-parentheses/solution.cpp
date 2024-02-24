class Solution {
public:
    void back(int aperte,int rim,string att, vector<string>& ris)
    {
        if(rim==0&&aperte==0)
        {
            ris.push_back(att);
            return;
        }
        if(rim==0)
            return;
        back(aperte+1,rim-1,att+'(',ris);
        if(aperte>0)
        back(aperte-1,rim-1,att+')',ris);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ris;
        back(0,n*2,"",ris);
        return ris;
    }
};
