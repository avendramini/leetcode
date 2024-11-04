class Solution {
public:
    string compressedString(string word) 
    {
        string att="";
        int i=0;
        while(i<word.size())
        {
            char c=word[i];
            int cont=1;
            i++;
            while(cont<9&&i<word.size()&&word[i]==c)
            {
                cont++;
                i++;
            }
            att+=to_string(cont);
            att+=c;
        }
        return att;
    }
};
