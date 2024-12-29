from collections import defaultdict

class Solution:
    def rico(self, pos, post, target, words, dp, char_count):
        if post == len(target):
            dp[pos][post] = 1
            return dp[pos][post]
        if pos == len(words[0]):
            dp[pos][post] = 0
            return dp[pos][post]
        if dp[pos][post] != -1:
            return dp[pos][post]

        tot = 0
        if target[post] in char_count[pos]:
            tot += char_count[pos][target[post]] * self.rico(pos + 1, post + 1, target, words, dp, char_count)
            tot %= 10**9 + 7
        tot += self.rico(pos + 1, post, target, words, dp, char_count)
        tot %= 10**9 + 7

        dp[pos][post] = tot
        return dp[pos][post]

    def numWays(self, words, target):
        n = len(words[0])
        m = len(target)

        # Precompute character counts for each position
        char_count = [defaultdict(int) for _ in range(n)]
        for word in words:
            for i, char in enumerate(word):
                char_count[i][char] += 1

        dp = [[-1 for _ in range(m + 1)] for _ in range(n + 1)]
        return self.rico(0, 0, target, words, dp, char_count)