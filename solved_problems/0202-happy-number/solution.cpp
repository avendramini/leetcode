class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
            return true;
        unordered_map<int,bool> seen;
        seen[n]=true;
        do
        {
            int sum=0;
            while(n!=0)
            {
                sum+= (n%10)*(n%10);
                n/=10;
            }
            n=sum;
            if(seen.count(sum))
                return false;
            seen[sum]=true;
        }while(n!=1);
        return true;
    }
};
