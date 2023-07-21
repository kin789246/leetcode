#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1, i;
        while (s <= e) {
            i = (s + e) / 2;
            if (nums[i] == target) return i;
            if (target < nums[i]) {
                e = i-1;
            }
            if (nums[i] < target) {
                s = i+1;
            }
        }
        
        return s;
    }
};

int main() {
    Solution solution;
    vector<int> n1{ 1, 3, 5, 6 };
    int t1{ 5 }; // 2
    std::cout << solution.searchInsert(n1,t1) << '\n';
    int t2{ 2 }; // 1
    std::cout << solution.searchInsert(n1, t2) << '\n';
    int t3{ 7 }; // 4
    std::cout << solution.searchInsert(n1, t3) << '\n';
    vector<int> n2{ 1, 3 };
    int t4{ 3 }; // 2
    std::cout << solution.searchInsert(n2, t4) << '\n';
    vector<int> n3{ 1, 2, 4, 6, 7 };
    int t5{ 3 }; // 2
    std::cout << solution.searchInsert(n3, t5) << '\n';
    return 0;
}

/*
35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2


Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
s = 0, e = 3, i = 2
n2 > t, s = 0, e = 1, i = 0
n0 < t, s = 1, e = 1, i = 1
n1 > t, s = 1, e = 0 => s>e return 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


nums = [1, 3], target = 3
output: 2
s = 0, e = 1, i = 0
t > n0 => e = 1, s = 1, i = 1
n1 == t return 1

nums = [1, 2, 4, 6, 7], target = 3
s=0, e=4, i = 2
n2 > 3 => s=0, e=1, i=0
n0 < 3 => s=1, e=1, i=1
n1 < 3 => s=2, e=1 => s>e return 2

Constraints:

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4
*/