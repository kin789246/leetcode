#include<iostream>
#include<vector>
#include<memory>
#include<queue>

#define null 100001

using std::unique_ptr, std::shared_ptr, std::queue, std::vector;

struct TreeNode {
    int value;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
    TreeNode() {}
    TreeNode(int v):value{v} {}
};

shared_ptr<TreeNode> Make_tree(vector<int> &v) {
    shared_ptr<TreeNode> tree = std::make_shared<TreeNode>(v[0]);
    int len = v.size();
    for (auto i=1; i<len; ++i) {
        queue<shared_ptr<TreeNode>> q;
        q.push(tree);
        while (!q.empty()) {
            shared_ptr<TreeNode> temp = q.front();
            q.pop();
            if (!temp->left) {
                temp->left = std::make_shared<TreeNode>(v[i]);
                break;
            }
            else {
                q.push(temp->left);
            }
            if (!temp->right) {
                temp->right = std::make_shared<TreeNode>(v[i]);
                break;
            }
            else {
                q.push(temp->right);
            }
        }
    }
    return tree;
}

class Solution {
    public:
    vector<int> Level_order(shared_ptr<TreeNode> tree) {
        vector<int> r;
        if (tree == nullptr) return r;
        queue<shared_ptr<TreeNode>> q;
        q.push(tree);
        while (!q.empty()) {
            shared_ptr<TreeNode> t = q.front();
            q.pop();
            r.push_back(t->value);
            if (t->left != nullptr) {
                q.push(t->left);
            }
            if (t->right != nullptr) {
                q.push(t->right);
            }
        }
        return r;
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
    vector<int> build{ 1, null, 2, 4 }; //error
    shared_ptr<TreeNode> tree = Make_tree(build);
    printVector(s.Level_order(tree));

    return 0;
}