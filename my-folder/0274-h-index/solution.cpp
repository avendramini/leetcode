class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        int n=citations.size();
        sort(citations.begin(),citations.end());
        int ris=0;
        for(int i=n-1;i>=0;i--)
        {
            if(citations[i]>=n-i)
            {
                ris=n-i;
            }
        }
        return ris;
    }
};
