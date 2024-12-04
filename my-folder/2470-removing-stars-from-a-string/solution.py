class Solution:
    def removeStars(self, s: str) -> str:
        st=deque()
        for x in s:
            if x=='*':
                st.pop()
            else:
                st.append(x)
        ris=""
        for x in st:
            ris+=x
        return ris

        

