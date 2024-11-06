class Solution {
public:
    bool isBalanced(string num) {
        vector<int> v(2);
        bool ok=false;
        for(auto x: num)
        {
                v[ok]+=(x-'0');
                ok=!ok;
        }
        return v[0]==v[1];
    }
};
