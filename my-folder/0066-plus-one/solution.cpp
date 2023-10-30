class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        digits[n-1]++;
        int i=n-1;
        while(i>0&&digits[i]>9)
        {
            digits[i]%=10;
            digits[i-1]++;
            i=i-1;
        }
        if(digits[0]>9){
            digits.insert(digits.begin(), 1);
            digits[1]%=10;
        }
        return digits;
    }
};
