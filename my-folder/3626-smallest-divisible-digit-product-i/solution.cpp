class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;;i++)
        {
             int tot=1;
            int copo=i;
            while(copo>0)
                {
                    tot*=(copo%10);
                    copo/=10;
                }
            if(tot%t==0)
                    return i;
        }
        return -1;
    }
};
