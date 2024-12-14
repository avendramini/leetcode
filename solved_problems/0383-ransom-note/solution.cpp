class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> occ(26,0);
        for(int i=0;i<magazine.size();i++)
        {
            occ[magazine[i]-97]++;
        }
        for(int i=0;i<ransomNote.size();i++)
        {
            if(occ[ransomNote[i]-97]==0)
                return false;
            occ[ransomNote[i]-97]--;
        }
        return true;
        
        
    }
};
