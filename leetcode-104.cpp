#include<iostream>
#include<vector>
#include<queue>

#define null 1000001

using std::queue, std::vector;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v):val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r):val(v), left(l), right(r) {}
};

TreeNode* Make_tree(vector<int> &v) {
    vector<TreeNode*> nodes;
    for (auto x : v) {
        if (x == null) nodes.push_back(nullptr);
        else nodes.push_back(new TreeNode(x));
    }
    int n = v.size();
    int j = 1;
    TreeNode* tree = nodes[0];
    for (int i=0; i<n; i++) {
        TreeNode* temp = nodes[i];
        if (temp != nullptr) {
            if (j < n) {
                temp->left = nodes[j];
                j++;
            }
            if (j < n) {
                temp->right = nodes[j];
                j++;
            }
        }
    }
    return tree;
}

void printVector(const vector<int>& v) {
    std::cout << "v -> ";
    for (auto& i : v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (root == nullptr) return 0;
            queue<TreeNode*> q;
            q.push(root);
            int ans = 0;
            while (!q.empty()) {
                int c = q.size();
                while (c--) {
                    TreeNode* tmp = q.front();
                    q.pop();
                    if (tmp->left != nullptr) {
                        q.push(tmp->left);
                    }
                    if (tmp->right != nullptr) {
                        q.push(tmp->right);
                    }
                }
                ans++;
            }
            return ans;
        }
};

int main() {
    Solution s;
    vector<int> build{ 3, 9, 20, null, null, 15, 7 }; // 3
    TreeNode* tree = Make_tree(build);
    std::cout << s.maxDepth(tree) << '\n';
    vector<int> build2{ 1, null, 2 }; // 2
    TreeNode* tree2 = Make_tree(build2);
    std::cout << s.maxDepth(tree2) << '\n';
    return 0;
}

/*
104. Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.



Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3


Example 2:
Input: root = [1,null,2]
Output: 2

Constraints:

The number of nodes in the tree is in the range [0, 10^4].
-100 <= Node.val <= 100
*/