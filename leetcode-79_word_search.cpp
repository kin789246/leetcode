#include<iostream>
#include<string>
#include<vector>
#include<chrono>

using std::string, std::vector; 

class Solution {
public:
    bool dfs(vector<vector<char>>& b, string& w, int r, int c, int i) {
        int ROWS = b.size();
        int COLS = b[0].size();

        if (i == w.size()) {
            return true;
        }

        if ( r < 0 || r >= ROWS || c < 0 || c >= COLS || w[i] != b[r][c] ) {
            return false;
        }
        
        b[r][c] = '*';
        bool result = ( dfs(b, w, r, c-1, i+1) ||
                dfs(b, w, r, c+1, i+1) ||
                dfs(b, w, r-1, c, i+1) ||
                dfs(b, w, r+1, c, i+1));
        b[r][c] = w[i];

        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int r=0; r<board.size(); r++) {
            for (int c=0; c<board[0].size(); c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution; 
    //vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}; 
    //string word = "SEE";
    vector<vector<char>> board = {
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'},
        {'A','A','A','A','A','A'}
    };
    string word = "AAAAAAAAAAAAAAa";
    
    auto start = std::chrono::steady_clock::now();

    std::cout << solution.exist(board, word) << '\n';

    auto end = std::chrono::steady_clock::now();
    std::cout << "Elapsed time in milliseconds: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
        << " ms\n";

    return 0; 
} 

/* 
79. Word Search
Given an m x n grid of characters board and a string word,
return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
word = "ABCB"
Output: false

Constraints:
m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.

Follow up: Could you use search pruning to make your solution faster with a larger board?


board = {
    {'A','A','A','A','A','A'},
    {'A','A','A','A','A','A'},
    {'A','A','A','A','A','A'},
    {'A','A','A','A','A','A'},
    {'A','A','A','A','A','A'},
    {'A','A','A','A','A','A'}
    };
word = "AAAAAAAAAAAAAAa";
 */
