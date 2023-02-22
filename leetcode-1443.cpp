#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>> &adj, vector<bool>& hasApple) {
        int totaltime = 0; 
        int childtime = 0;
        for (auto child : adj[node]) {
            if (child == parent) continue;
            childtime = dfs(child, node, adj, hasApple);
            if (childtime || hasApple[child])
                totaltime += childtime + 2;
        }

        return totaltime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // create adjacency list 
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0, -1, adj, hasApple);

        // int i=0;
        // for (auto &a : adj) {
        //     std::cout << i++ << " -> ";
        //     for (auto &i : a) {
        //         std::cout << i << ' ';
        //     }
        //     std::cout << '\n';
        // }

        return 0;
    }
};

int main() {
    int n=7;
    vector<vector<int>> edges{ {0,1} ,{0,2},{1,4},{1,5},{2,3},{2,6} };
    vector<bool> hasApple { false, false, true, false, true, true, false };
    Solution s;
    std::cout << s.minTime(n, edges, hasApple) << '\n';

    return 0;
}