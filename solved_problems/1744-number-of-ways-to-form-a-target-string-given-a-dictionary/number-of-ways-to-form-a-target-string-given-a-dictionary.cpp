#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int rico(int pos, int post, const string& target, const vector<string>& words, vector<vector<int>>& dp, const vector<vector<int>>& charCount) {
        if (post == target.size()) {
            return dp[pos][post] = 1;
        }
        if (pos == words[0].size()) {
            return dp[pos][post] = 0;
        }
        if (dp[pos][post] != -1) {
            return dp[pos][post];
        }

        long long tot = 0;
        if (charCount[pos][target[post] - 'a'] > 0) {
            tot += (long long)charCount[pos][target[post] - 'a'] * rico(pos + 1, post + 1, target, words, dp, charCount);
            tot %= 1000000007;
        }
        tot += rico(pos + 1, post, target, words, dp, charCount);
        tot %= 1000000007;

        dp[pos][post] = static_cast<int>(tot);
        return dp[pos][post];
    }

    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int m = target.size();

        // Precompute character counts for each position
        vector<vector<int>> charCount(n, vector<int>(26, 0));
        for (const auto& word : words) {
            for (int i = 0; i < n; ++i) {
                charCount[i][word[i] - 'a']++;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return rico(0, 0, target, words, dp, charCount);
    }
};