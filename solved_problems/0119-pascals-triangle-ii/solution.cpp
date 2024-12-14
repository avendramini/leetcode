class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> att(1);
        att[0]=1;
        if(rowIndex==0)
            return att;
        att.push_back(1);
        for(int i=2;i<=rowIndex;i++)
        {
            vector<int> nuovo;
            nuovo.push_back(1);
            for(int i=0;i<att.size()-1;i++)
                {
                    nuovo.push_back(att[i]+att[i+1]);
                }
            nuovo.push_back(1);
            att=nuovo;
        }
        return att;
    }
};
