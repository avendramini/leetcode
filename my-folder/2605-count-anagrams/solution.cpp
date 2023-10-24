class Solution {
    #define ll long long
public:
#define ll long long
const ll mod=1e9+7;
ll fact[(int)1e5+1];

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
 
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
 
    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
 
// Function to find modulo inverse of a
int modInverse(ll A, ll M)
{
    ll x, y;
    ll g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        return 0;
    else {
 
        // m is added to handle negative x
        ll res = (x % M + M) % M;
        return res;
    }
}
 

int countAnagrams(string s) 
{
    fact[0]=1;
    for(int i=1;i<1e5+1;i++)
    {   
        fact[i]=(fact[i-1]*i)%mod;
    }
    vector<string> stringhe;
    for(int i=0;i<s.size();i++)
    {
        string creata="";
        while(i<s.size()&&s[i]!=' ')
        {
            creata+=s[i];
            i++;
        }
        stringhe.push_back(creata);
    }
    ll tot=1;
    for(int j=0;j<stringhe.size();j++)
    {
        vector<int> occ(26,0);
        for(int i=0;i<stringhe[j].size();i++)
        {
            occ[stringhe[j][i]-'a']++;
        }
        ll att=fact[stringhe[j].size()];
        for(int i=0;i<26;i++)
        {
            if(occ[i]>1)
            {
                att*=(ll)modInverse(fact[occ[i]],mod)%mod;
                att%=mod;
            }
        }

        tot*=att;
        tot%=mod;
    }

    return tot;
    
}
};
