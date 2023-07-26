/*
    133. Clone Graph
    https://leetcode.com/problems/clone-graph/description/
*/
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using std::vector, std::cout, std::set, std::queue, std::map;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        map<Node*, Node*> cloned;
        queue<Node*> q1;
        cloned[node] = new Node(node->val);
        q1.push(node);
        while (!q1.empty()) {
            Node *t = q1.front();
            q1.pop();
            for (auto neighbor : t->neighbors) {
                if (cloned.find(neighbor) == cloned.end()) {
                    q1.push(neighbor);
                    cloned[neighbor] = new Node(neighbor->val);
                }
                cloned[t]->neighbors.push_back(cloned[neighbor]);
            }
        }
        return cloned[node];
    }
};

Node* build_graph(vector<vector<int>> &adjacency) {
    if (adjacency.empty()) return nullptr;
    vector<Node*> G;
    for (int i = 0; i < adjacency.size(); i++) {
        G.push_back(new Node(i+1));
    }
    for (int i=0; i<adjacency.size(); i++) {
        for (int n : adjacency[i]) {
            G[i]->neighbors.push_back(G[n-1]);
        }
    }
    return G[0];
}

void show_graph(Node* graph) {
    if (graph == nullptr) {
        cout << "empty graph\n";
        return;
    }
    map<int, Node*> g;
    queue<Node*> q;
    q.push(graph);
    g[graph->val] = graph;
    while (!q.empty()) {
        Node *t = q.front();
        q.pop();
        for (auto neighbor : t->neighbors) {
            if (g.find(neighbor->val) == g.end()) {
                q.push(neighbor);
                g[neighbor->val] = neighbor;
            }
        }
    }
    for (auto iter=g.begin(); iter!=g.end(); iter++) {
        cout << "vertex [" << iter->second->val << "] has neighbors: ";
        for (auto n : iter->second->neighbors) {
            cout << n->val << ", ";
        }
        cout << "\n";
    }
}

int main() {
    // adjList = [[2,4],[1,3],[2,4],[1,3]]
    vector<vector<int>> adjList{{2,4}, {1,3}, {2,4}, {1,3}};
    Node* graph = build_graph(adjList);
    Solution s = Solution();
    cout << "original graph\n";
    show_graph(graph);
    cout << "\ncloned graph\n";
    show_graph(s.cloneGraph(graph));
    cout << '\n';
    return 0;
}