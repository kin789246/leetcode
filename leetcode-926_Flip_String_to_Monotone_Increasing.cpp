#include<iostream>
#include<string>

using std::string;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans=0, num=0;
        for (auto c:s) {
            if (c == '0') {
                ans = std::min(num, ans+1);
            }
            else {
                num++;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s{ "010110" };
    std::cout << solution.minFlipsMonoIncr(s) << '\n';

    return 0;
}