class StockSpanner:

    def __init__(self):
        self.s=deque()

    def next(self, price: int) -> int:
        if len(self.s)==0:
            self.s.appendleft((price,0))
            return 1
        print(price)
        cont=0
        while len(self.s)>0 and self.s[0][0]<=price:
            print(f"daje {self.s[0]}")
            cont+=self.s[0][1]+1
            self.s.popleft()
        
        self.s.appendleft((price,cont))
        return cont+1

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
