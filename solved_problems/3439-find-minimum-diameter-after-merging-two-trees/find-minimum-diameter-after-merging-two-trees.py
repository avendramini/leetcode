class Solution:
    def farthestDfs(self, pos,p, adj,count):
        
        farthest=(count,pos)
        for x in adj[pos]:
            if x!=p:
                farthest=max([farthest,self.farthestDfs(x, pos, adj, count+1)])
        return farthest

    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        adj= [[] for _ in range(len(edges1)+1)]
        for edge in edges1:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])

        first_diam=self.farthestDfs(self.farthestDfs(0, -1, adj, 0)[1], -1, adj, 0)[0]

        adj= [[] for _ in range(len(edges2)+1)]
        for edge in edges2:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])

        second_diam=self.farthestDfs(self.farthestDfs(0, -1, adj, 0)[1], -1, adj, 0)[0]

        comb_diam=ceil(first_diam/2)+ceil(second_diam/2)+1
        return max([comb_diam,first_diam,second_diam])