class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        prefix_sum_count = defaultdict(int)
        prefix_sum_count[0] = 1  # Initialize for cases where path sum directly equals targetSum
        return self.dfs(root, 0, targetSum, prefix_sum_count)

    def dfs(self, node: Optional[TreeNode], current_sum: int, target_sum: int, prefix_sum_count: Dict[int, int]) -> int:
        if not node:
            return 0

        current_sum += node.val
        count = prefix_sum_count.get(current_sum - target_sum, 0)

        prefix_sum_count[current_sum] += 1
        
        # Recursively check left and right subtrees
        count += self.dfs(node.left, current_sum, target_sum, prefix_sum_count)
        count += self.dfs(node.right, current_sum, target_sum, prefix_sum_count)
        
        # Remove the current path sum count to ensure it doesn't affect other paths
        prefix_sum_count[current_sum] -= 1
        
        return count
