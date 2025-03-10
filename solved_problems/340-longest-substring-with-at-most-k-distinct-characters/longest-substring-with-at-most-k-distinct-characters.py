class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        m={}
        left=0
        right=0
        ris=0
        while right<len(s):
            m[s[right]]=right
            right+=1
            if len(m)>k:
                index=min(m.values())
                del m[s[index]]
                left=index+1
            ris=max([ris,right-left])
        return ris

            