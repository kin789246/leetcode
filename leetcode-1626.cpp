#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using std::vector, std::pair;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> pairs;
        int n = scores.size();
        for (int i=0; i<n; i++) {
            pairs.push_back(pair<int,int>{ages[i], scores[i]});
        }
        std::sort(pairs.begin(), pairs.end());
        vector<int> dp = vector<int>(n);
        int ans = 0;
        for (int i=0; i<n; i++) {
            dp[i] = pairs[i].second;
            ans = std::max(dp[i], ans);
        }
        for (int i=0; i<n; i++) {
            for (int j=i-1; j>=0; j--) {
                if (pairs[i].second >= pairs[j].second) {
                    dp[i] = std::max(dp[i], pairs[i].second+dp[j]);
                }
            }
            ans = std::max(dp[i], ans);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> s{ 4,5,6,5 }, s2{ 1,3,5,10,15 }, s3{ 1,2,3,5 }, s4{ 9,2,8,8,2 };
    vector<int> a{ 2,1,2,1 }, a2{ 1,2,3,4,5 }, a3{ 8,9,10,1 }, a4{ 4,1,3,3,5 };
    std::cout << solution.bestTeamScore(s, a) << '\n'; //16
    std::cout << solution.bestTeamScore(s2, a2) << '\n'; //34
    std::cout << solution.bestTeamScore(s3, a3) << '\n'; //6
    std::cout << solution.bestTeamScore(s4, a4) << '\n';  //27
    return 0;
}

/*
Example 1:

Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
Output: 34
Explanation: You can choose all the players.
Example 2:

Input: scores = [4,5,6,5], ages = [2,1,2,1]
[1,1,2,2]
[5,5,4,6]
Output: 16
Explanation: It is best to choose the last 3 players. 
Notice that you are allowed to choose multiple people of the same age.
Example 3:

Input: scores = [1,2,3,5], ages = [8,9,10,1]
[1,8,9,10]
[5,1,2,3]
Output: 6
Explanation: It is best to choose the first 3 players.


[9,2,8,8,2] [4,1,3,3,5]
[1,3,3,4,5]
[2,8,8,9,2]

Constraints:

1 <= scores.length, ages.length <= 1000
scores.length == ages.length
1 <= scores[i] <= 106
1 <= ages[i] <= 1000
*/