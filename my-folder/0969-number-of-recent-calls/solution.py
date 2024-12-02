from collections import deque
class RecentCounter:
    def __init__(self):
        self.ok=deque()

    def ping(self, t: int) -> int:
        self.ok.append(t)
        while(self.ok[0]<t-3000):
            self.ok.popleft()
        return len(self.ok)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
