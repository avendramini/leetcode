class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ris;
        for(int i=1;i<=n;i++)
        {
            if(i%3==0)
            {
                if(i%5==0)
                {
                    ris.push_back("FizzBuzz");
                }
                else
                {
                    ris.push_back("Fizz");
                }
            }
            else if(i%5==0)
            {
                ris.push_back("Buzz");
            }
            else
            {
                ris.push_back(to_string(i));
            }
        }
        return ris;
    }
};
