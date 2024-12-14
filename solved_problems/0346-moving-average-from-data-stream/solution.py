class MovingAverage:

    def __init__(self, size: int):
        self.q=deque()
        self.size=size
        self.sum=0

    def next(self, val: int) -> float:
        if self.size==len(self.q):
            self.sum-=self.q[0]
            self.q.popleft()
            self.sum+=val
            self.q.append(val)
        else:
            self.sum+=val
            self.q.append(val)
        return self.sum/min([self.size,len(self.q)])

# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
