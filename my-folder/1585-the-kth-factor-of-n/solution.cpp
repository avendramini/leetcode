class Solution {
public:
    int kthFactor(int n, int k) {
        int cont=0;
        for(int i=1;i<=n/2;i++)
        {
            if(n%i==0)
            {
                cont++;
                if(cont==k)
                    return i;
            }
        }
        if(cont==k-1)
            return n;
        return -1;
    }
};
