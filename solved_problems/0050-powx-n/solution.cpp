class Solution {
public:
    double myPow(double x, int n) {
        if(n==1)
            return x;
        if(n==-1)
            return 1.0/x;
        if(n==0)
            return 1.0;
        if(n%2==0){
            double ris=myPow(x,n/2);
            return ris*ris;
        }
        else
        return x*myPow(x,n-1);
    }
};
