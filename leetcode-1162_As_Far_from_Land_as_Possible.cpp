#include<iostream>
#include<vector>
#include<queue>

using std::cout, std::vector, std::queue, std::pair;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited = vector<vector<int>>(n, vector<int>(n));
        pair<int,int> directions[4] = {{0,1},{0,-1},{-1,0},{1,0}};
        queue<pair<int,int>> q;
        int distance = -1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    visited[i][j] = grid[i][j];
                    q.push({i,j});
                }
            }
        }
        while (!q.empty()) {
            int q_size = q.size();
            while (q_size--) {
                pair<int,int> land_cell = q.front();
                q.pop();
                for (auto &d : directions) {
                    int x = land_cell.first + d.first;
                    int y = land_cell.second + d.second;
                    if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0) {
                        if (grid[x][y]==0) {
                            visited[x][y] = 1;
                            grid[x][y] = 1;
                            q.push({x,y});
                        }
                    }
                }
            }
            distance++;
        }
        return distance==0 ? -1 : distance;
    }
};

int main() {
    Solution s;
    vector<vector<int>> g1 = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}; // 2
    cout << s.maxDistance(g1) << '\n';
    vector<vector<int>> g2 = { {1, 0, 0}, {0, 0, 0}, {0, 0, 0} }; // 4
    cout << s.maxDistance(g2) << '\n';
    return 0;
}

/*
1162. As Far from Land as Possible
Medium
2.8K
75
Companies
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.



Example 1:


Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:


Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.


Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
*/