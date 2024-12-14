class Solution {
public:
    void back(int pos,vector<int> att,int last,int n,int k,vector<vector<int> > &ris)
    {
        if(pos==k)
        {
            ris.push_back(att);
            return;
        }
        for(int i=last+1;i<=n;i++)
        {
            att.push_back(i);
            back(pos+1,att,i,n,k,ris);
            att.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ris;
        if(k==0)
        return {};
        back(0,{},0,n,k,ris);
        return ris;
    }
};
