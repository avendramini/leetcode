class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        long long x=0;
        x&=right;
        long long pow=1;
        long long manca=0;
        long long mask=0;
        for(int i=0;i<=30;i++)
        {
            mask|=pow;
            
            if((left&pow)==pow)
            {
                int parte=left&mask;
                manca=pow-(parte-pow);
                if(left+manca>right)
                    x|=pow;

            }
            pow*=2;
        }
        return x;
    }
};
