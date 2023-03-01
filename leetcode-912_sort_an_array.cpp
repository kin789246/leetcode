#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    // merge sort algorithm, Time = O(nlog_n), space =O(n)
    
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int m = l + (r-l)/2;
        merge_sort(nums, l, m);
        merge_sort(nums, m+1, r);
        merge(nums, l, r, m);
    }
    void merge(vector<int>&nums, int l, int r, int m) {
        int idx_l = l, idx_r = m+1;
        vector<int> auxiliary;
        while (idx_l<=m && idx_r<=r) {
            if (nums[idx_l] < nums[idx_r]) {
                auxiliary.push_back(nums[idx_l]);
                idx_l++;
            }
            else {
                auxiliary.push_back(nums[idx_r]);
                idx_r++;
            }
        }
        while (idx_l <= m) {
            auxiliary.push_back(nums[idx_l++]);
        }
        while (idx_r <= r) {
            auxiliary.push_back(nums[idx_r++]);
        }
        for (int n : auxiliary) {
            nums[l++] = n;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, (int)nums.size()-1);
        return nums;
    }
};

int main() {
    vector<int> nums1{5, 1, 1, 2, 0, 0};
    Solution solution;
    for (int n:solution.sortArray(nums1)) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    return 0;
}

/*
912. Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity 
and with the smallest space complexity possible.


Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), 
while the positions of other numbers are changed (for example, 1 and 5).


Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.

Constraints:
1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4
*/