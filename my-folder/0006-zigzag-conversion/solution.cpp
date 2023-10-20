class Solution {
public:
    string convert(string s, int numRows) {
        int cont=0;
        bool modo=true;
        vector<string> tot(numRows,"");
        for(int i=0;i<s.size();i++)
        {
            tot[cont]+=s[i];
            if(cont==numRows-1)
            {
                modo=false;
            }
            else if(cont==0)
                modo=true;
            if(modo)
                cont++;
            else 
                cont--;
            cont%=numRows;
            cont=max(cont,0);
        }
        string ris="";
        for(auto x: tot)
            ris+=x;
        return ris;

    }
};
