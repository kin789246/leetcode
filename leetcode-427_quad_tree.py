from sys import maxsize
from typing import Optional, List

class Node:
    def __init__(self, val, isLeaf, topLeft=None, topRight=None, bottomLeft=None, bottomRight=None):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
    def print_tree(self):
        print('[', self.isLeaf, ',', self.val, ']')
        if self.topLeft:
            self.topLeft.print_tree()
        if self.topRight:
            self.topRight.print_tree()
        if self.bottomLeft:
            self.bottomLeft.print_tree()
        if self.bottomRight:
            self.bottomRight.print_tree()

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def construct_range(top, left, side_length):
            if side_length == 1:
                return Node(grid[top][left], 1)
            top_left = construct_range(top, left, side_length//2)
            top_right = construct_range(top, left+side_length//2, side_length//2)
            bottom_left = construct_range(top+side_length//2, left, side_length//2)
            bottom_right = construct_range(top+side_length//2, left+side_length//2, side_length//2)
            children = [top_left, top_right, bottom_left, bottom_right]
            if all(child.val==top_left.val and child.isLeaf for child in children):
                return Node(top_left.val, 1)
            return Node(1, 0, top_left, top_right, bottom_left, bottom_right)
        
        return construct_range(0, 0, len(grid))

if __name__ == '__main__':
    s = Solution()
    grid = [[0,1],[1,0]]  # Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
    tree = s.construct(grid)
    tree.print_tree()

