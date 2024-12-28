class Solution:
    def rico(self, pos, closed, k, nums, dp, prefix):
        # Base case: If three subarrays are already selected, the maximum sum is 0
        if closed == 3:
            dp[pos][closed] = 0
            return dp[pos][closed]
        
        # If the subarray exceeds the array bounds, return a very small value
        if pos + k > len(nums):
            return -1e9
        
        # If already computed, return the memoized value
        if dp[pos][closed] != -1:
            return dp[pos][closed]
        
        # Option 1: Include the subarray starting at 'pos'
        rico1 = self.rico(pos + k, closed + 1, k, nums, dp, prefix) + prefix[pos + k] - prefix[pos]
        
        # Option 2: Skip the current position and move forward
        rico2 = self.rico(pos + 1, closed, k, nums, dp, prefix)
        
        # Take the maximum of both options and store it in dp
        massimo = max([rico1, rico2])
        dp[pos][closed] = massimo
        return dp[pos][closed]
    
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        # Compute the prefix sum array
        prefix = [0] * (len(nums) + 1)
        for i, x in enumerate(nums):
            prefix[i + 1] = prefix[i] + x
        
        # Initialize the DP table
        dp = [[-1 for _ in range(4)] for _ in range(len(nums) + 1)]
        
        # Compute the maximum sum using the recursive function
        self.rico(0, 0, k, nums, dp, prefix)

        # Reconstruct the solution to find the starting indices of the three subarrays
        ris = []
        pos = (0, 0)
        while pos[1] != 3:
            # Check if including the subarray starting at 'pos' leads to the optimal solution
            if pos[0] + k <= len(nums) and pos[1] < 3 and dp[pos[0] + k][pos[1] + 1] + prefix[pos[0] + k] - prefix[pos[0]] == dp[pos[0]][pos[1]]:
                ris.append(pos[0])  # Append the starting index
                pos = (pos[0] + k, pos[1] + 1)  # Move to the next valid position
            else:
                pos = (pos[0] + 1, pos[1])  # Otherwise, skip to the next position
        
        return ris