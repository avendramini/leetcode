class Solution:
    def __init__(self):
        self.visited={}
    def rico(self,tiles,pos, sel,count):
        if pos==len(tiles):
            if len(sel)==0:
                return 0
            ok=str(sorted(sel))
            if ok in self.visited:
                return 0
            ris=factorial(len(sel))
            for x in count.keys():
                print(count[x])
                ris/=factorial(count[x])
            print(f"{ok} - {ris}")
            self.visited[ok]=True
            return ris
        ris=self.rico(tiles,pos+1,sel,count)
        sel.append(tiles[pos])
        if tiles[pos] not in count:
            count[tiles[pos]]=0
        count[tiles[pos]]+=1
        ris+=self.rico(tiles,pos+1,sel,count)
        count[tiles[pos]]-=1
        sel.pop()
        return ris
    
        

    def numTilePossibilities(self, tiles: str) -> int:
        return int(self.rico(tiles,0,[],{}))