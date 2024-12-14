class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>res;
        vector<int>uniqueOne;
        unordered_set<int>n1(nums1.begin(), nums1.end());
        unordered_set<int>n2(nums2.begin(), nums2.end());
        for (auto x : n1){
            if (n2.count(x) == 0){uniqueOne.push_back(x);}
            else {n2.erase(x);}
        }
        res.push_back(uniqueOne);
        vector<int>uniqueTwo(n2.begin(), n2.end());
        res.push_back(uniqueTwo);
        return res;
    }
};
