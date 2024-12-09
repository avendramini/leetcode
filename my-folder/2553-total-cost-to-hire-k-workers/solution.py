from queue import PriorityQueue
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        qleft=PriorityQueue()
        qright=PriorityQueue()
        somma=0
        left=candidates
        right=len(costs)-1-candidates
        for i in range(0,candidates):
            if i<=len(costs)-i-1:
                qleft.put((costs[i],i))
                left=i+1
                if i<len(costs)-i-1:
                    qright.put((costs[len(costs)-i-1],i))
                    right=len(costs)-i-2
        
        
        while k>0:
            print(right)
            print(left)
            if qleft.qsize()==0:
                print("ok")
                somma+=qright.get()[0]
                k-=1
                continue
            elif qright.qsize()==0:
                print("ok2")
                somma+=qleft.get()[0]
                k-=1
                continue
            primo=qleft.get()
            secondo=qright.get()
            if (primo[0]<=secondo[0] ):
                somma+=primo[0]
                print("primo")
                print(primo[0])
                qright.put(secondo)
                if left<=right:
                    qleft.put((costs[left],left))
                    left+=1
            else:
                somma+=secondo[0]
                qleft.put(primo)
                print(secondo[0])
                if right>=left:
                    qright.put((costs[right],right))
                    right-=1
            
            k-=1
        return somma
