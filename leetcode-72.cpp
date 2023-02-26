#include<iostream>
#include<string>
#include<vector>

using std::string, std::vector;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n_s1=word1.length()+1, n_s2=word2.length()+1;
        vector<vector<int>> dp(n_s2, vector<int>(n_s1));
        for (int i=0; i<n_s2; i++) {
            for (int j=0; j<n_s1; j++) {
                if (i==0) {
                    dp[i][j] = j;
                }
                else if (j==0) {
                    dp[i][j] = i;
                }
                else if (word2[i-1] == word1[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = std::min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[n_s2-1][n_s1-1];
    }
};

int main() {
    Solution solution;
     string a0{ "horse" }, b0{ "ros" }; // 3
     std::cout << solution.minDistance(a0, b0) << '\n';
    return 0;
}

/*
72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.


*/