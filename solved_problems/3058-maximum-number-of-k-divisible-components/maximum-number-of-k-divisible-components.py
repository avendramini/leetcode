class Solution:
    def dfs(self, pos, vis, adj, values, k, dp):
        vis[pos] = True
        leaf = True
        
        # Check if current node is a leaf
        for x in adj[pos]:
            if not vis[x]:
                leaf = False
                
        if leaf:
            # If it's a leaf, initialize dp
            if values[pos] % k == 0:
                dp[pos] = ((values[pos], 0), (0, 1))
            else:
                dp[pos] = ((values[pos], 0), (0, -1))
            return
        
        # Sum and count of partitions
        somma = values[pos]
        parti = 0
        
        for x in adj[pos]:
            if not vis[x]:
                self.dfs(x, vis, adj, values, k, dp)
                if dp[x][1][1] != -1:
                    parti += dp[x][1][1]
                else:
                    parti += dp[x][0][1]
                    somma += dp[x][0][0]
        
        # Update dp based on divisibility by k
        if somma % k == 0:
            dp[pos] = ((0, parti + 1), (0, parti + 1))
        else:
            dp[pos] = ((somma, parti), (0, -1))
        return

    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        # Build adjacency list
        adj = [[] for _ in range(n)]
        for x in edges:
            adj[x[0]].append(x[1])
            adj[x[1]].append(x[0])
        
        # Initialize visited array and dp
        vis = [False] * n
        dp = [()] * n
        
        # Start DFS from node 0
        self.dfs(0, vis, adj, values, k, dp)
        
        # Return the maximum number of components
        return max(dp[0][1][1], dp[0][0][1])