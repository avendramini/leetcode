class Solution {
public:
    vector<int> conf;
    map<int,vector<int> > matches;
    void backtrack(int val,int len,int m)
    {
        if(len==m)
        {
            conf.push_back(val);
            return;
        }
        for(int i=1;i<=3;i++)
        {
            if(val%10!=i)
            {
                backtrack(val*10+i,len+1,m);
            }
        }

    }
    void find_matches()
    {
        for(auto val: conf)
        {
            for(auto x: conf)
            {
                int copy_val=val;
                int copy_x=x;
                bool ok=true;
                while(copy_x>0)
                {
                    int x_digit=copy_x%10;
                    int val_digit=copy_val%10;
                    if(x_digit==val_digit)
                        ok=false;
                    copy_val/=10;
                    copy_x/=10;
                }
                if(ok)
                {
                    matches[val].push_back(x);
                }
            }
        }
    }
    int colorTheGrid(int m, int n) {
        backtrack(0,0,m);
        find_matches();
        map<pair<int,int>, long long> dp;
        for(auto x: conf)
        {
            dp[{0,x}]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int x: conf)
            {
                for(int comp:matches[x])
                {
                    dp[{i,x}]+=dp[{i-1,comp}]%((int)1e9+7);
                    dp[{i,x}]%=((int)1e9+7);
                }
            }
        }
        long long ris=0;
        for(int x :conf)
        {
            ris+=dp[{n-1,x}];
            ris%=((int)1e9+7);
        }


        return ris;
    }
};