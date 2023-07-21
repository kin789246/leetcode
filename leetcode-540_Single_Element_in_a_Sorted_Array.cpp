#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int s=0, e=n-1, m;
        while (s <= e) {
            m = (s + e) / 2;
            if (m%2==0) {
                if (nums[m] != nums[m+1])
                    e = m-1;
                else
                    s = m+1;
            }
            else {
                if (nums[m] == nums[m+1])
                    e = m-1;
                else
                    s = m+1;
            }
        }
        return nums[s];
    }
};

int main() {
    Solution s;
    vector<int> n1{ 1, 1, 2, 3, 3, 4, 4, 8, 8 }; // 2
    std::cout << s.singleNonDuplicate(n1) << '\n';
    vector<int> n2{ 3, 3, 7, 7, 10, 11, 11 }; // 10
    std::cout << s.singleNonDuplicate(n2) << '\n';
    vector<int> n3{ 1 }; // 1
    std::cout << s.singleNonDuplicate(n3) << '\n';
    vector<int> n4{ 1, 1, 2}; // 2
    std::cout << s.singleNonDuplicate(n4) << '\n';
    return 0;
}

/*
540. Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.


Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
s=0 e=8 m=4 => n[4]!=n[4+1], n[4]==n[4-1] => left
s=0 e=3 m=1 => n[1]!=n[1+1], n[1]==n[1-1] => right
s=2 e=3 m=2 => n[2]!=n[2+1], n[2]!=n[2-1] => return n[m]

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
s=0 e=6 m=3 =>n[3]!=n[3+1], n[3]==n[3-1] => right
s=4 e=6 m=5 =>n[5]==n[5+1], n[5]!=n[5-1] => left
s=4 e=4 return n[4]

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/