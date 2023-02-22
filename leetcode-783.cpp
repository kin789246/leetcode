#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits>

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

class Solution {
    public:
        int minDiffInBST(TreeNode* root) {
            int ans = std::numeric_limits<int>::max();
            queue<TreeNode*> q;
            vector<int> v;
            q.push(root);
            while (!q.empty()) {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }

            std::sort(v.begin(), v.end());
            for (int i=1; i<(int)v.size(); i++) {
                ans = std::min(ans, v[i]-v[i-1]);
            }
            
            return ans;
        }
};

void printVector(const vector<int> &v) {
    std::cout << "v -> ";
    for (auto &i : v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main() {
    Solution s;
    vector<int> build{ 1, 0, 48, null, null, 12, 49 }; // 1
    TreeNode* tree = Make_tree(build);
    std::cout << s.minDiffInBST(tree) << '\n';
    vector<int> build2{ 90, 69, null, 49, 89, null, 52 }; // 1
    TreeNode* tree2 = Make_tree(build2);
    std::cout << s.minDiffInBST(tree2) << '\n';
    return 0;
}

/*
783. Minimum Distance Between BST Nodes
Easy

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1

Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1

Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 10^5
*/