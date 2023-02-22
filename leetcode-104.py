from sys import maxsize
from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def make_tree(s):
    nodes = [None if v=='null' else TreeNode(int(v)) for v in s.split(',')]
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
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        ans = 0
        q:List[TreeNode] = []
        q.append(root)
        while len(q) != 0:
            size = len(q)
            while size != 0:
                t = q.pop(0)
                if t.left != None:
                    q.append(t.left)
                if t.right != None:
                    q.append(t.right)
                size -= 1
            ans += 1
        return ans  

if __name__ == '__main__':
    s = Solution()
    r1 = "3,9,20,null,null,15,7"
    t1 = make_tree(r1)
    print(s.maxDepth(t1)) # 3
    r2 = "1,null,2"
    t2 = make_tree(r2)
    print(s.maxDepth(t2)) # 2
