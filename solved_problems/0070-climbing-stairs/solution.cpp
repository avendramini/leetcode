class Solution {
public:
    int climbStairs(int n) 
    {
        
        int last=1,last2=1;
        for(int i=2;i<=n;i++)
        {
            int app=last;
            last=last+last2;
            swap(last2,app);
        }
        return last;
    }
};
