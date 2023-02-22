from sys import maxsize
from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def make_tree(s):
    nodes = [None if v=='null' else TreeNode(int(v)) for v in s.split(', ')]
    kids = nodes[::-1]
    root = kids.pop()
    for node in nodes:
        if node:
            if kids:
                node.left = kids.pop()
            if kids:
                node.right = kids.pop()
    return root

class Solution:
    def in_order(self, root:Optional[TreeNode], v:List[int]):
        if root == None:
            return
        self.in_order(root.left, v)
        v.append(root.val)
        self.in_order(root.right, v)
        
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        ans = maxsize
        v = []
        self.in_order(root, v)
        for i in range(1, len(v)):
            ans = min(ans, v[i]-v[i-1])
            
        return ans
    

if __name__ == '__main__':
    s = Solution()
    r1 = "1, 0, 48, null, null, 12, 49"
    t1 = make_tree(r1)
    print(s.minDiffInBST(t1)) # 1
    r2 = "90, 69, null, 49, 89, null, 52"
    t2 = make_tree(r2)
    print(s.minDiffInBST(t2)) # 1
    r3 = "4, 2, 6, 1, 3"
    t3 = make_tree(r3)
    print(s.minDiffInBST(t3))  # 1
