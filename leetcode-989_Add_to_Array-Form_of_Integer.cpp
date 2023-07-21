#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        for (int in=num.size()-1; in>=0; in--) {
            num[in] = carry + num[in] + k % 10;
            carry = num[in] / 10;
            num[in] %= 10;
            k /= 10;
            if (k==0 && carry==0) break;
        }
        k += carry;
        while (k) {
            num.insert(num.begin(), k%10);
            k /= 10;
            carry = 0;
        }
        if (carry) num.insert(num.begin(), carry);
        return num;
    }
};

void printVector(const vector<int>& v) {
    std::cout << "[ ";
    for (auto& i : v) {
        std::cout << i << ' ';
    }
    std::cout << "]\n";
}

int main() {
    Solution solution;
    vector<int> n1{ 1,2,0,0 };
    int k1 = 34; // 1234
    printVector(solution.addToArrayForm(n1,k1));
    vector<int> n2{ 2,7,4 };
    int k2 = 181; // 455
    printVector(solution.addToArrayForm(n2, k2));
    vector<int> n3{ 2,1,5 };
    int k3 = 806; // 1021
    printVector(solution.addToArrayForm(n3, k3));
    vector<int> n4{ 9,9,9,9,9,9,9,9,9,9 };
    int k4 = 1; // [1,0,0,0,0,0,0,0,0,0,0]
    printVector(solution.addToArrayForm(n4, k4));
    return 0;
}

/*
989. Add to Array-Form of Integer
Easy
2K
185
Companies
The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.



Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021


Constraints:

1 <= num.length <= 10^4
0 <= num[i] <= 9
num does not contain any leading zeros except for the zero itself.
1 <= k <= 10^4
*/