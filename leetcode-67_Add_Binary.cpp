#include<iostream>
#include<string>

using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "0" && b == "0") return "0";
        int da, db, carry = 0;
        string ans;
        int ia = a.size()-1, ib = b.size()-1;
        while (true) {
            if (ia < 0 && ib < 0) break;
            if (ia < 0) {
                da = 0;
            }
            else {
                da = a[ia] == '0' ? 0 : 1;
            }
            if (ib < 0) {
                db = 0;
            }
            else {
                db = b[ib] == '0' ? 0 : 1;
            }
            ia--; ib--;
            switch (da + db + carry) {
                case 0:
                    carry = 0;
                    ans.insert(0, 1, '0');
                    break;
                case 1:
                    carry = 0;
                    ans.insert(0, 1, '1');
                    break;
                case 2:
                    carry = 1;
                    ans.insert(0, 1, '0');
                    break;
                case 3:
                    carry = 1;
                    ans.insert(0, 1, '1');
                    break;
                default:
                    break;
            }
        }
        if (carry == 1) {
            ans.insert(0, 1, '1');
        }
        return ans;
    }
};

int main() {
    Solution solution;
     string a0{ "11" }, b0{ "1" }; // 100
     std::cout << solution.addBinary(a0, b0) << '\n';
    //string a1{ "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101" }, 
    //    b1{ "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011" };
    //std::cout << solution.addBinary(a0, b0) << '\n';
    return 0;
}

/*
67. Add Binary
Easy
6.9K
715
Companies
Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

a =
"10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101"
b =
"110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/