#include<iostream>
#include<string>
#include<numeric>

using std::string;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1+str2 != str2+str1) {
            return "";
        }
        int gcd_len_base = std::gcd(str1.length(), str2.length());
        return str1.substr(0, gcd_len_base);
    }
};

int main() {
    Solution solution;
    string s1{ "ABCABC" };
    string s2{ "ABC" };
    std::cout << solution.gcdOfStrings(s1,s2) << '\n';

    return 0;
}

/*
Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""


Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
*/