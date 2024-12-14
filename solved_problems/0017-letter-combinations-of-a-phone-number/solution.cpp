class Solution {
public:
    vector<string> v={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void back(string digits,int pos, string att,vector<string>& ris)
    {
        if(pos==digits.size())
        {
            if(att!="")
            ris.push_back(att);
            return;
        }
        for(auto x: v[digits[pos]-'2'])
        {
            back(digits,pos+1,att+x,ris);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ris;
        back(digits,0,"",ris);
        return ris;
    }
};
