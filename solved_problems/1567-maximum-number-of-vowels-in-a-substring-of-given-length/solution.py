class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        cont=0
        maxi=0
        vowel={'a','e','i','o','u'}
        for i in range(0,k):
            if s[i] in vowel:
                cont+=1
        maxi=cont
        for i in range(k,len(s)):
            if s[i-k] in vowel:
                cont-=1
            if s[i] in vowel:
                cont+=1
            maxi=max([maxi,cont])
        return maxi

