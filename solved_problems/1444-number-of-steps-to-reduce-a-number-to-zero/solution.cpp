class Solution {
public:
    int numberOfSteps(int num) {
        int n=0;
        while(num!=0)
        {
            n++;
            if(num%2)
            {
                num--;
            }
            else
                num/=2;
        }
        return n;
    }
};
