class Solution {
public:
    int titleToNumber(string columnTitle) 
    {
        int tot=0;
        for(int i=columnTitle.size()-1;i>=0;i--)
        {
            tot+=((columnTitle[i]-'A')+1)*pow(26,columnTitle.size()-1-i);
        }
        return tot;
    }
};
