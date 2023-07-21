#include<iostream>
#include<string>

using std::string;

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int r = 0;
        int i = 0;
        while (i < len) {
            switch (s[i]) {
            case 'I':
                if (s[i+1] == 'V') {
                    r += 4;
                    i += 2;
                }
                else if (s[i+1] == 'X' ) {
                    r += 9;
                    i += 2;
                }
                else {
                    r += 1;
                    i++;
                }
                break;
            case 'X':
                if (s[i + 1] == 'L') {
                    r += 40;
                    i += 2;
                }
                else if (s[i + 1] == 'C') {
                    r += 90;
                    i += 2;
                }
                else {
                    r += 10;
                    i++;
                }
                break;
            case 'C':
                if (s[i + 1] == 'D') {
                    r += 400;
                    i += 2;
                }
                else if (s[i + 1] == 'M') {
                    r += 900;
                    i += 2;
                }
                else {
                    r += 100;
                    i++;
                }
                break;
            case 'M':
                r += 1000;
                i ++;
                break;
            case 'D':
                r += 500;
                i++;
                break;
            case 'L':
                r += 50;
                i++;
                break;
            case 'V':
                r += 5;
                i++;
                break;
            default:
                break;
            }
        }
        
        return r;
    }
};

int main() {
    Solution solution;
    string s{ "MCMXCIV" };
    std::cout << solution.romanToInt(s) << '\n';
    string s2{ "III" };
    std::cout << solution.romanToInt(s2) << '\n';
    string s3{ "LVIII" };
    std::cout << solution.romanToInt(s3) << '\n';
    return 0;
}

/*
Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/