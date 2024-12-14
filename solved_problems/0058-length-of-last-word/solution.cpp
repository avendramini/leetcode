class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int fine=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                fine=i;
                break;
            }
        }
        int inizio=0;
        for(int i=fine;i>=0;i--)
        {
            if(s[i]==' ')
            {
                inizio=i+1;
                break;
            }
        }
        return fine-inizio+1;
    }
};
