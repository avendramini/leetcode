class StringIterator:

    def __init__(self, compressedString: str):
        self.att=0
        self.cont=0
        self.conteggio=0
        self.s=compressedString
        i=1
        while i<len(self.s) and self.s[i].isdigit():
            self.conteggio*=10
            self.conteggio+=int(self.s[i])
            i+=1
        


    def next(self) -> str:
        if self.att>=len(self.s):
            return " "
        string=self.s[self.att]
        self.cont+=1
        if self.cont==self.conteggio:
            self.att+=len(str(self.conteggio))+1
            i=self.att+1
            self.conteggio=0
            self.cont=0
            while i<len(self.s) and self.s[i].isdigit():
                self.conteggio*=10
                self.conteggio+=int(self.s[i])
                i+=1
            
        return string
            

    def hasNext(self) -> bool:
        return (len(str(self.conteggio))+self.att)<len(self.s)


# Your StringIterator object will be instantiated and called as such:
# obj = StringIterator(compressedString)
# param_1 = obj.next()
# param_2 = obj.hasNext()