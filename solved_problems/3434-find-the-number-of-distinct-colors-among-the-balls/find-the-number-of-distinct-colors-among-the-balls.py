class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        color_count={}
        ball_color={}
        ris=[]
        for (x,y) in queries:
            if x in ball_color:
                color_count[ball_color[x]]-=1
                if color_count[ball_color[x]]==0:
                    del color_count[ball_color[x]]
            ball_color[x]=y
            if y not in color_count:
                color_count[y]=0
            color_count[y]+=1
            ris.append(len(color_count))
        return ris
            
                