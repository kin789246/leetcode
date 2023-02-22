#include<iostream>
#include<vector>
#include<map>
using std::vector, std::map;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n < 2) return n;
        map<int, int> types;
        types[fruits[0]]++;
        int max_picks = 2;
        int l, r;
        for (l=0, r=1; l<n && r<n;) {
            types[fruits[r++]]++;
            if (types.size() > 2) {
                if (types[fruits[l]]<=1) {
                    types.erase(fruits[l]);
                }
                else {
                    types[fruits[l]]--;
                }
                l++;
            }
            max_picks = std::max(max_picks, (r-l));
        }
        return max_picks;
    }
};

int main() {
    Solution solution;
    vector<int> f1{ 1,2,1 }; // 3
    std::cout << solution.totalFruit(f1) << '\n';
    vector<int> f2{ 0,1,2,2 }; // 3
    std::cout << solution.totalFruit(f2) << '\n';
    vector<int> f3{ 1,2,3,2,2 }; // 4
    std::cout << solution.totalFruit(f3) << '\n';
    vector<int> f4{ 3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4 }; // 5
    std::cout << solution.totalFruit(f4) << '\n';
    return 0;
}

/*
Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].


Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length
*/