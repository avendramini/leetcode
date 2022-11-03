class Solution {
public:
    int romanToInt(string s) {
        int ris=0;
        int prev=1e9;
        int att=0;
        for(int i=0;i<s.size();i++)
        {
            switch(s[i])
            {
                case 'I':
                    att=1;
                    break;
                case 'V':
                    att=5;
                    break;
                case 'X':
                    att=10;
                    break;
                case 'L':
                    att=50;
                    break;
                case 'C':
                    att=100;
                    break;
                case 'D':
                    att=500;
                    break;
                case 'M':
                    att=1000;
                    break;
            }
            if(att>prev)
            {
                ris-=prev*2;
            }
            ris+=att;
            prev=att;
        }
        return ris;
    }
};
