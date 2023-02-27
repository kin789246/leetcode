#include<iostream>
#include<vector>
#include<queue>

using std::vector, std::queue;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
    void print() {
        queue<Node*> q;
        q.push(this);
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size > 0) {
                Node* t = q.front();
                q.pop();
                q_size--;
                if (!t) {
                    std::cout << "[null]";
                    continue;
                }
                std::cout << '[' << t->isLeaf << ',' << t->val << ']';
                if (t->topLeft) {
                    q.push(t->topLeft);
                }
                else {
                    q.push(nullptr);
                }
                if (t->topRight) {
                    q.push(t->topRight);
                }
                else {
                    q.push(nullptr);
                }
                if (t->bottomLeft) {
                    q.push(t->bottomLeft);
                }
                else {
                    q.push(nullptr);
                }
                if (t->bottomRight) {
                    q.push(t->bottomRight);
                }
                else {
                    q.push(nullptr);
                }
            }
        }
    }
};

class Solution {
public:
    Node* construct_range(vector<vector<int>>& grid, int top, int left, int side_length) {
        if (side_length == 1) {
            return new Node{(bool)grid[top][left], 1};
        }
        //children nodes
        Node *topleft = construct_range(grid, top, left, side_length/2);
        Node *topright = construct_range(grid, top, left+side_length/2, side_length/2);
        Node *bottomleft = construct_range(grid, top+side_length/2, left, side_length/2);
        Node *bottomright = construct_range(grid, top+side_length/2, left+side_length/2, side_length/2);
        //if all children values are the same and all are leaves
        if (topleft->val == topright->val &&
            topleft->val == bottomleft->val &&
            topleft->val == bottomright->val &&
            topleft->isLeaf && topright->isLeaf && bottomleft->isLeaf && bottomright->isLeaf) {
            return new Node{ topleft->val, 1 };
        }
        return new Node{1, 0, topleft, topright, bottomleft, bottomright};
    }

    Node* construct(vector<vector<int>>& grid) {
        return construct_range(grid, 0, 0, (int)grid.size());
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid1{  {1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0, 0, 0, 0}}; 
    // [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
    Node* ans = s.construct(grid1);

    // Node quad_tree{1, 0};
    // quad_tree.topLeft = new Node{0, 1};
    // quad_tree.topRight = new Node{1, 1};
    // quad_tree.bottomLeft = new Node{1, 1};
    // quad_tree.bottomRight = new Node{0, 1};

    std::cout << '[';
    if (ans) ans->print();
    else std::cout << "[null]";
    std::cout << "]\n";
    return 0;
}

/*
427. Construct Quad Tree

Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.
Return the root of the Quad-Tree representing the grid.

Notice that you can assign the value of a node to True or False when isLeaf is False, and both are accepted in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:
val: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
isLeaf: True if the node is leaf node on the tree or False if the node has the four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.

If you want to know more about the Quad-Tree, you can refer to the wiki.
https://en.wikipedia.org/wiki/Quadtree

Quad-Tree format:

The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.
It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].
If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.

Constraints:

n == grid.length == grid[i].length
n == 2^x where 0 <= x <= 6
*/