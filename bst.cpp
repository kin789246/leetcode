#include<iostream>
#include<vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode *l, TreeNode *r)
        : val(v), left(l), right(r) {}
};

class BST {
    public:
    int find_max(TreeNode*);
    int find_min(TreeNode*);
    int tree_height(TreeNode*);
    bool contains(TreeNode*, int);
    void insert(TreeNode**, int);
    TreeNode* remove(TreeNode*, int);
    void inorder_trav(TreeNode*);
};

int BST::find_max(TreeNode* node) {
    if (node == nullptr) return 0;
    if (node->right == nullptr) return node->val;
    return find_max(node->right);
}
int BST::find_min(TreeNode* node) {
    if (node == nullptr) return 0;
    if (node->left == nullptr) return node->val;
    return find_min(node->left);
}
int BST::tree_height(TreeNode* node) {
    if (node == nullptr) return 0;
    return 1+std::max(tree_height(node->left), tree_height(node->right));
}
bool BST::contains(TreeNode* node, int val) {
    if (node == nullptr) return false;
    if (node->val == val) return true;
    if (node->val < val) return contains(node->right, val);
    return contains(node->left, val);
}

void BST::insert(TreeNode** node, int val) {
    if (*node == nullptr) {
        *node = new TreeNode(val);
    }
    else if ((*node)->val < val) insert(&(*node)->right, val);
    else if ((*node)->val > val) insert(&(*node)->left, val);
}

TreeNode* BST::remove(TreeNode* node, int val) {
    if (node == nullptr) return node;
    if (node->val < val) {
        node->right = remove(node->right, val);
        return node;
    }
    if (node->val > val) {
        node->left = remove(node->left, val);
        return node;
    }
    // one child empty cases
    if (node->left == nullptr) {
        TreeNode* temp = node->right;
        delete node;
        return temp;
    }
    if (node->right == nullptr) {
        TreeNode* temp = node->left;
        delete node;
        return temp;
    } 
    // exist both children
    TreeNode* successor_parent = node;
    TreeNode* succesor = node->right;
    // find the minimum of the right children
    while (succesor->left != nullptr) {
        successor_parent = succesor;
        succesor = succesor->left;
    }
    if (successor_parent != node) {
        successor_parent->left = succesor->right;
    }
    else {
        successor_parent->right = succesor->right;
    }
    node->val = succesor->val;
    delete succesor;
    return node;
}

void BST::inorder_trav(TreeNode* root) {
    if (root) {
        inorder_trav(root->left);
        std::cout << root->val << " -> ";
        inorder_trav(root->right);
    }
}

int main() {
    std::vector<int> scores{40, 50, 20, 70, 10, 55, 25, 80, 3, 65, 15, 45};
    BST bst;
    TreeNode *tree = nullptr;
    for (int s: scores) {
        bst.insert(&tree, s);
    }
    //std::cout << "tree height: " << bst.tree_height(tree) << '\n';
    //std::cout << "tree contains 33 -> " << bst.contains(tree, 33) << '\n';
    bst.inorder_trav(tree);
    std::cout << "end\n";
    bst.remove(tree, 50);
    bst.inorder_trav(tree);
    std::cout << "end\n";
    return 0;
}