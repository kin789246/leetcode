
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
using std::vector;
using std::stack;
using std::queue;

#define null 10001

//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void insertNode(TreeNode **root, int val) {
    queue<TreeNode*> que1;
    que1.push(*root);
    while (!que1.empty()) {
        TreeNode *curr = que1.front();
        que1.pop();
        if (!curr->left) {
            curr->left = new TreeNode(val);
            std::cout << "(l)" << val << ' ';
            return;
        }
        else {
            if (curr->left->val != null)
                que1.push(curr->left);
        }
        if (!curr->right) {
            curr->right = new TreeNode(val);
            std::cout << "(r)" << val << ' ';
            return;
        }
        else {
            if (curr->right->val != null)
                que1.push(curr->right);
        }
    }
}

TreeNode* createTree(const vector<int> &tree) {
    TreeNode *root = new TreeNode(tree[0]);
    std::cout << "make tree\n(root)" << tree[0] << ' ';
    for (int i=1; i<tree.size(); ++i) {
        insertNode(&root, tree[i]);
    }
    std::cout << "\n-end-\n";
    return root;
}

void printVector(const vector<int> &v) {
    std::cout << "v-> ";
    for (auto i : v) {
        if (i != null) std::cout << i << ',';
        else std::cout << "null" << ',';
    }
    std::cout << '\n';
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            if (cur != nullptr) {
                r.push_back(cur->val);
                s.push(cur->right);
                s.push(cur->left);
            }
        }

        return r;
    }

    vector<int> levelTraversal(TreeNode* tree) {
        vector<int> r;
        queue<TreeNode*> q;
        q.push(tree);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            r.push_back(tmp->val);
            if (tmp->left != nullptr) {
                q.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                q.push(tmp->right);
            }
        }
        
        return r;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==nullptr && q==nullptr) return true;
        if (p==nullptr || q==nullptr) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution s;
    TreeNode *p;
    p = createTree(vector<int>{1, 2, 6, null, null, 3, 5, null, 67});

    vector<int> rp = s.levelTraversal(p);
    printVector(rp);

    return 0;
}