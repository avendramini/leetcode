class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int somma=0;
        for(int i=0;i<n;i++)
            somma+=nums[i];
        if(somma<target)
            return 0;
        int minimo=0;
        int massimo=n;
        int medio;
        int ris=n;
        while(minimo<=massimo)
        {
            medio=(minimo+massimo)/2;
            bool ok=false;
            int sum=0;
            for(int i=0;i<medio;i++)
                sum+=nums[i];
            if(sum>=target)
                ok=true;
            for(int i=medio;i<n;i++)
            {
                sum-=nums[i-medio];
                sum+=nums[i];
                if(sum>=target)
                    ok=true;
            }

            if(ok)
            {
                ris=min(ris,medio);
                massimo=medio-1;
            }
            else
            minimo=medio+1;
        }
        return ris;

    }
};
