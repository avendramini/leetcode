class TrieNode:
   def __init__(self):
       self.children = defaultdict(TrieNode)
       self.isWord = False

class Trie:
   def __init__(self):
       self.root = TrieNode()

   def insert(self, word):
       cur = self.root
       for w in word:
           cur = cur.children[w] 
       cur.isWord = True

class Solution:
   def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
       m, n = len(board), len(board[0])
       res = []
       trie = Trie()
       for word in words:
           trie.insert(word)
       for i in range(m):
           for j in range(n):
               if board[i][j] in trie.root.children:
                   self.dfs(board, i, j, trie.root.children[board[i][j]], [], res)
       return res
   
   def dfs(self, board, i, j, node, path, res):
       m, n = len(board), len(board[0])
       path.append(board[i][j])
       tmp = board[i][j]
       board[i][j] = "#"
       if node.isWord:
           res.append("".join(path))
           node.isWord = False
       for di, dj in ((0, 1), (0, -1), (1, 0), (-1, 0)):
           ni, nj = i + di, j + dj
           if 0 <= ni < m and 0 <= nj < n and board[ni][nj] in node.children:
               self.dfs(board, ni, nj, node.children[board[ni][nj]], path, res)
       path.pop()
       board[i][j] = tmp
