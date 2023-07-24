#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using std::vector, std::cout, std::string;
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

std::ostream& operator<<(std::ostream& os, const TreeNode* t) {
    if (t != nullptr)
        os << t->val;
    else
        os << "null";
    return os;
}

template<typename T>
void print_vector_T(const vector<T>& v) {
    for (auto item : v) {
        cout << item << '\n';
    }
    cout << '\n';
}

class BinaryTree
{
private:
    vector<string> parse(const string&);
public:
    TreeNode* build(const string&);
    void test_private_function();
};

TreeNode* BinaryTree::build(const string& input) {
    vector<TreeNode*> nodes;
    for (string& s : parse(input)) {
        if (s == "null") {
            nodes.push_back(nullptr);
        }
        else {
            nodes.push_back(new TreeNode(std::stoi(s)));
        }
    }
    vector<TreeNode*> kids = vector<TreeNode*>(nodes);
    std::reverse(kids.begin(), kids.end());
    TreeNode* out = kids.back();
    kids.pop_back();
    for (auto node: nodes) {
        if (node != nullptr) {
            if (!kids.empty()) {
                node->left = kids.back();
                kids.pop_back();
            }
            if (!kids.empty()) {
                node->right = kids.back();
                kids.pop_back();
            }
        }
    }
    return out;
}

vector<string> BinaryTree::parse(const string& input) {
    vector<string> output;
    string str = input.substr(1, input.size()-2);
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    char delimit = ',';
    int start = 0, end = 0;
    while (end < str.size()) {
        if (str[end] == delimit) {
            output.push_back(str.substr(start, end-start));
            start = end + 1;
        }
        end++;
    }
    output.push_back(str.substr(start, end-start));
    return output;
} 

void BinaryTree::test_private_function() {
    string s = "[-10, 9, 20, null, null, 15, 7]";
    vector<string> output = parse(s);
    print_vector_T<string>(output);
}

int main() {
    BinaryTree binary_tree1;
    binary_tree1.build("[-10, 9, 20, null, null, 15, 7]");
    return 0;
}