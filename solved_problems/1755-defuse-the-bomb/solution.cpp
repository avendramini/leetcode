class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ris;
        if(k==0)
        {
            for(auto x: code)
                ris.push_back(0);
            
        }
        else
        {
            
            for(int i=0;i<code.size();i++)
            {
                int tot=0;
                for(int j=1;j<=abs(k);j++)
                {
                    if(k<0)
                    {
                        tot+=code[(i-j+code.size())%code.size()];
                    }
                    else
                    {
                        tot+=code[(i+j+code.size())%code.size()];
                    }
                }
                ris.push_back(tot);
            }
        }
        return ris;
        

    }
};
