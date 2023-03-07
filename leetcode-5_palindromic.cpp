#include<iostream>
#include<string>

using std::cout, std::string;

class Solution {
public:
    string check(string &s, int i, int j) {
        int n = s.size();
        while (0<=i && j<n) {
            if (s[i] == s[j]) {
                i--;
                j++;
                //cout << "i=" << i << " j=" << j << '\n';
            }
            else break;
        }
        return s.substr(i+1, j-i-1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 1;
        string ans{s[0]};
        for (int i = 0; i < n; i++)
        {
            string s1 = check(s, i, i);
            string s2 = check(s, i, i+1);
            //cout << s1 << ' ' << s2 << '\n';
            if (max_len < (int)s1.size()) {
                max_len = (int)s1.size();
                ans = s1;
            }
            if (max_len < (int)s2.size()) {
                max_len = (int)s2.size();
                ans = s2;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s1{"aaaa"}; // aaaa
    cout << solution.longestPalindrome(s1) << '\n';
    string s2{ "cbbd" }; // bb
    cout << solution.longestPalindrome(s2) << '\n';
    string s3{ "a" }; // a
    cout << solution.longestPalindrome(s3) << '\n';
    s3 = { "ac" }; // a
    cout << solution.longestPalindrome(s3) << '\n';
    return 0;
}

/*
5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters.

0123456
abcdcba
M[i] = length of palindromic ith as middle
M[0] = 0
M[1] = 0 -> check M[0] != M[2]
M[2] = 0 -> check M[1] != M[3]
M[3] = 3 -> check M[2] == M[4]
M[4] = 0
M[5] = 0
M[6] = 0
*/