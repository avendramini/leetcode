class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<pair<pair<int,int>, char> > > mem; 
    int n;
    string s1;
    int ris(int pos,int pos2)
    {
        if(dp[pos][pos2]!=-1){

            return dp[pos][pos2];
        }
        if(pos>pos2){
        mem[pos][pos2]={{-1,-1},'1'};
        return dp[pos][pos2]=0;
        }
        if(pos==pos2){
            mem[pos][pos2]={{-1,-1},s1[pos]};
            return dp[pos][pos2]=1;
        }
        
        int maxi=0;
        pair<pair<int,int>, char> sos;
        int ans;
        if(s1[pos]==s1[pos2])
        {
            ans=ris(pos+1,pos2-1)+2;
            if(ans>=maxi){
                maxi=ans;
                sos={{pos+1,pos2-1},s1[pos]};    
            }
        }
        ans=ris(pos+1,pos2);
        if(ans>=maxi){
            maxi=ans;
            sos={{pos+1,pos2},'1'};    
        }
        ans=ris(pos,pos2-1);
        if(ans>=maxi){
            maxi=ans;
            sos={{pos,pos2-1},'1'};    
        }
        mem[pos][pos2]=sos;
        return dp[pos][pos2]=maxi;
    }
    int longestPalindromeSubseq(string s) {
        
        n=s.size();
        s1=s;
        dp.assign(n,vector<int>(n,-1));
        mem.assign(n,vector<pair<pair<int,int>, char> >(n,{{-1,-1},'1'}));
        int part=ris(0,n-1);
        return part;
    }
};
