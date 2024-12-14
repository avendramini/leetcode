class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        s=deque()
        for x in asteroids:
            if x<0:
                add=True
                while True:
                    #print(s)
                    if len(s)>0:
                        p=s[-1]
                        if p>0:
                            if p==-x:
                                s.pop()
                                add=False
                                break
                            elif p<-x:                               
                                s.pop()
                                add=True
                            else:
                                add=False
                                break
                        else:
                            add=True
                            break
                    else:
                        break  
                if add:
                    s.append(x)
            else:
                s.append(x)

        return list(s)
