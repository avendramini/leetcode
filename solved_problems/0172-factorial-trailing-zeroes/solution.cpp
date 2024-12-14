class Solution {
public:
    int trailingZeroes(int n) 
    {
        int cont5=0;
        int cont2=0;
        for(int i=1;i<=n;i++)
        {
            int num=i;
            while(num%2==0)
                cont2++,num/=2;
            while(num%5==0)
                cont5++,num/=5;
        }
        return min(cont5,cont2);
    }
};
