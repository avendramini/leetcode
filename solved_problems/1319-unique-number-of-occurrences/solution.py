class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        m={}
        for x in arr:
            if x in m:
                m[x]+=1
            else:
                m[x]=1
        print(list(m.values()))
        print(list(set(m.values())))
        return  sorted(list(m.values()))==sorted(list(set(m.values())))
