#include<iostream>
#include<vector>
#include<map>

using std::vector;
using std::map;

class Solution {
public:
    bool findPath(vector<int>& vals, map<int, vector<int>>& edge_able, int start, int end) {
        if (vals[start] == vals[end]) return true;
        
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int r = 0;
        map<int,vector<int>> edge_table;
        for (auto & e : edges) {
            edge_table[e[0]].push_back(e[1]);
            edge_table[e[1]].push_back(e[0]);
        }
        for (int start=0; start<vals.size(); start++) {
            for (int end=0; end<vals.size(); end++) {
                if (start == end) {
                    r++;
                }
                else {
                    continue;
                }
            }
        }

        return r;
    }
};

int main() {
    Solution s;
    vector<int> vals{1, 3, 2, 1, 3};
    vector<vector<int>> edges{ {0, 1}, {0, 2}, {2, 3}, {2, 4} };
    //output = 6;

    std::cout << s.numberOfGoodPaths(vals, edges) << '\n';

    return 0;
}