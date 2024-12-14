class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        app=[-n for n in gifts]
        heapq.heapify(app)
        for k in range(0,k):
            heapq.heapreplace(app, -int(sqrt(-app[0])))
        return -sum(app)

