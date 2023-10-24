class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> conv={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,int> m;
        for(int i=0;i<words.size();i++)
        { 
            string ris="";
            for(int j=0;j<words[i].size();j++)
            {
                ris+=conv[words[i][j]-'a'];
            }
            m[ris]++;
        }
        return m.size();
    }
};
