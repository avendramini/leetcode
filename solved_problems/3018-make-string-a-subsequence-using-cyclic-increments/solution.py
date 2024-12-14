class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        nuova=""
        for x in str1:
            nuova+=x
            nuova+=chr((ord(x) - ord('a') + 1) % 26 + ord('a'))
        print(nuova)
        j=0
        for i in range(0,len(nuova)):
            if i%2==1:
                continue
            if nuova[i]==str2[j] or nuova[i+1]==str2[j]:
                j+=1

            if j==len(str2):
                return True
        return False
