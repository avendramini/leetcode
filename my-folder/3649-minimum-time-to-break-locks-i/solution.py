class Solution:
    def findMinimumTime(self, strength: List[int], K: int) -> int:
        
        def dfs(strength, factor):
            # Caso base: se non ci sono più lucchetti
            if not strength:
                return 0
            
            # Prova a rompere ogni lucchetto e scegli il minimo tempo
            min_time = 1e9
            for i in range(len(strength)):
                # Calcola il tempo per rompere il lucchetto corrente
                time_to_break = ceil(strength[i] / factor)
                # Calcola il tempo rimanente usando ricorsione
                restante = strength[:i] + strength[i+1:]
                min_time = min(min_time, time_to_break + dfs(restante, factor + K))
            
            return min_time
        
        return dfs(strength, 1)
            

            
