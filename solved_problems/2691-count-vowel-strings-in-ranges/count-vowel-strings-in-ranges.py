class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        prefix=[0]*(len(words)+1)
        for i,x in enumerate(words):
            if x[0] in 'aeiou' and x[len(x)-1] in 'aeiou':
                prefix[i+1]=prefix[i]+1
            else:
                prefix[i+1]=prefix[i]
        ris=[]
        for x in queries:
            ris.append(prefix[x[1]+1]-prefix[x[0]])
        return ris