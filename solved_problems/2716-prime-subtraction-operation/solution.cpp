class Solution {
public:


    bool primeSubOperation(vector<int>& nums) {
        vector<bool> primes(1000 + 1, true);

        // Since 0 and 1 is not prime, mark them false
        primes[0] = primes[1] = false;

        // Mark all the multiples of numbers from
        // 2 to sqrt(n) as false
        for (int i = 2; i * i <= 1000; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= 1000; j += i)
                    primes[j] = false;
            }
        }
        for(int j=nums[0]-1;j>=0;j--)
        {
            if(primes[j])
            {
                nums[0]-=j;
                break;
            }
        }

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
                return false;
            
            for(int j=nums[i]-nums[i-1]-1;j>=0;j--)
            {
                if(primes[j])
                {
                    nums[i]-=j;
                    break;
                }
            }
        }
        for(auto x: nums)
            cout<<x<<" ";
        cout<<endl;
        return true;
    }
};
