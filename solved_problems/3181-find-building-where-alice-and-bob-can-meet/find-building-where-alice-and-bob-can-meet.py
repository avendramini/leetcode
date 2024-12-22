
class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        # Adjacency list for queries
        adj = [[] for _ in range(len(heights))]
        # Result array initialized to -1
        ris = [-1 for _ in range(len(queries))]

        # Preprocess queries
        for i, x in enumerate(queries):
            destra = max(x)
            massimo = max(heights[x[0]], heights[x[1]])
            if massimo == heights[destra] and heights[x[0]] != heights[x[1]]:
                ris[i] = destra
            elif x[0] == x[1]:
                ris[i] = x[0]
            else:
                adj[destra].append((massimo, i))

        # Priority queue for processing queries
        s = []
        for i, x in enumerate(heights):
            for q in adj[i]:
                heapq.heappush(s, q)
            while len(s) > 0 and s[0][0] < heights[i]:
                ris[s[0][1]] = i
                heapq.heappop(s)

        return ris