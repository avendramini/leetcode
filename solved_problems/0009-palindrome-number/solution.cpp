class Solution {
public:
    bool isPalindrome(int x) {
        
        string cifre=to_string(x);
        for(int i=0;i<cifre.size();i++)
        {
            if(cifre[i]!=cifre[cifre.size()-1-i])
                return false;
        }
        return true;
    }
};
