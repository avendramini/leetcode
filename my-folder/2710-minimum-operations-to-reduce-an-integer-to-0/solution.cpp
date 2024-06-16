class Solution {
public:
    int minOperations(int n) {
       vector<int> bits(32,0);int ans=0;
        for(int i=0;i<32;i++)
        {
            bits[31-i]=n&1; n=n>>1;
        }
        for(int i =0; i<32; i++)
        {
            cout << bits[i] << " ";
        }
        for(int i=31; i>=0; i--)
        {
            if(bits[i]==1)
            {
                if(i-1>=0 && bits[i-1]==0)
                {
                    ans++;
                    continue;
                }
                while(i>=0 && bits[i]==1)
                {
                    i--;
                }
                ans++;
                if(i>=0)
                bits[i] = 1;
                i++;
            }
        }
        return ans;
    }
};
