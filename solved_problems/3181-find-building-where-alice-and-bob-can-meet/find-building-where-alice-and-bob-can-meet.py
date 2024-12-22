class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        #per ogni query estraggo la coppia (Indice più a destra, elemento massimo)
        #se l'elemento massimo è nell'indice più a destra allora posso già dare la risposta di quella query
        #mi creo un adj in cui pusho questi massimi in una lista dell'indice più a destra
        #inizio a scorrere dall'inizio il vettore heights, tengo un set/coda priorità ordinata in cui pusho gli elementi di quell'indice, dopo di chè lì poppo fino a quando heights è minore dell'elemento in testa alla coda (segnando le risposte per le query)
        # passo all'elemento successivo e faccio lo stesso
        #gli elementi ancora nel set alla fine di questo avranno risposta -1

        adj=[[] for _ in range(len(heights))]
        ris=[-1 for _ in range(len(queries))]
        for i,x in enumerate(queries):
            destra=max(x)
            massimo=max([heights[x[0]],heights[x[1]]])
            if massimo==heights[destra] and heights[x[0]]!=heights[x[1]]:
                ris[i]=destra
            elif x[0]==x[1]:
                ris[i]=x[0]
            else:
                adj[destra].append((massimo,i))
        
        s=[]
        for i,x in enumerate(heights):
            for q in adj[i]:
                heapq.heappush(s, q)
            while len(s)>0 and s[0][0]<heights[i]:
                ris[s[0][1]]=i
                heapq.heappop(s)
        return ris