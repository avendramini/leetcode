class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        pref=[0]
        for a in gain:
            pref.append(pref[-1]+a)
        return max(pref)
