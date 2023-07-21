#include<iostream>
#include<string>
#include<vector>

using std::string, std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows == int(s.length())) return s;
        vector<string> zigzag_table = vector<string>(numRows);
        int cur = 0, r = 0; 
        int direct = 1;
        while (s[cur]!='\0') {
            zigzag_table[r] += s[cur];
            if (r == 0) direct = 1;
            if (r == numRows-1) direct = -1;
            r = r + direct;
            cur++;
        }
        string result;
        for (auto &str : zigzag_table) {
            result += str;
        }
        return result;
    }
};

int main() {
    Solution solution;
    int n0{ 1 };
    string s0{ "AB" }; // AB
    std::cout << solution.convert(s0, n0) << '\n';

    // int n1{3};
    // string s1{ "PAYPALISHIRING" }; // PAHNAPLSIIGYIR
    // std::cout << solution.convert(s1,n1) << '\n';

    // int n2{ 4 };
    // string s2{ "PAYPALISHIRING" }; // PINALSIGYAHRPI
    // std::cout << solution.convert(s2, n2) << '\n';

    // int n3{ 1 };
    // string s3{ "A" }; // A
    // std::cout << solution.convert(s3, n3) << '\n';

    return 0;
}

/*
6. Zigzag Conversion
Medium
5K
10.7K
Companies
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

PAYPALISHIRING

P   H
A  SI
Y I R
PL  IG
A   N

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/