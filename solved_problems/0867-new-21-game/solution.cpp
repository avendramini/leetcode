class Solution {
public:
    double new21Game(int N, int K, int maxPts) {
        // Corner cases
        if (K == 0) return 1.0;
        if (N >= K-1 + maxPts) return 1.0;

        // dp[i] is the probability of getting point i.
        vector<double> dp(N + 1, 0.0);

        double probability = 0.0; // dp of N or less points.
        double windowSum = 1.0; // Sliding required window sum
        dp[0] = 1.0;
        for (int i = 1; i <= N; i++) {
            dp[i] = windowSum / maxPts;
            //probability of getting ith point is more than i/max as we have more than on draws to get points and we are taking sum of all the previous probabilities to add as the new chances then dibide total by max

            if(i < K) windowSum += dp[i];
            else probability += dp[i];
            
            if(i >= maxPts) windowSum -= dp[i - maxPts];
        }

        return probability;
    }
};
