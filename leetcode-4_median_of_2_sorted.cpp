#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2=nums2.size();
        int n = (n1 + n2)/2 + 1;
        int i=0, j=0, c=0, cur=0, pre=0;
        // if (n1==0) {
        //     cur = nums2[0];
        //     pre = nums2[0];
        // }
        // else if (n2==0) {
        //     cur = nums1[0];
        //     pre = nums1[0];
        // }
        // else if (nums1[0]<nums2[0]) {
        //     cur = nums1[0];
        //     pre = nums1[0];
        // }
        // else {
        //     cur = nums2[0];
        //     pre = nums2[0];
        // }
        while (i < n1 && j < n2) {
            c++;
            if (c == n) {
                if (i < n1 && j < n2) {
                    if (nums1[i] < nums2[j]) cur = nums1[i];
                    else cur = nums2[j];
                }
                else if (i < n1 && j >= n2) {
                    cur = nums1[i];
                }
                else if (j < n2 && i >= n1) {
                    cur = nums2[j];
                }
                break;
            }
            if (nums1[i] < nums2[j]) {
                pre = nums1[i++];
            }
            else {
                pre = nums2[j++];
            }
        }
        std::cout << "i=" << i << " j=" << j << " c=" << c << " cur=" << cur << " pre=" << pre << '\n';
        while (i<n1 && c<n) {
            c++;
            if (c == n) {
                cur = nums1[i];
                break;
            }
            else {
                pre = nums1[i];
                i++;
            }
        }
        std::cout << "i=" << i << " j=" << j << " c=" << c << " cur=" << cur << " pre=" << pre << '\n';
        while (j<n2 && c<n) {
            c++;
            if (c == n) {
                cur = nums2[j];
                break;
            }
            else {
                pre = nums2[j];
                j++;
            }
        }
        std::cout << "i=" << i << " j=" << j << " c=" << c << " cur=" << cur << " pre=" << pre << '\n';
        if ((n1+n2)%2 == 0) {
            return (cur + pre) / 2.0;
        }
        else {
            return cur;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1{ 1, 3 };
    vector<int> nums2{ 2 };
    std::cout << solution.findMedianSortedArrays(nums1, nums2) << '\n';
    // vector<int> nums3{ 1, 3 };
    // vector<int> nums4{ 2, 7 };
    // std::cout << solution.findMedianSortedArrays(nums3, nums4) << '\n';
    // vector<int> nums1{ 0, 0, 0, 0, 0 };
    // vector<int> nums2{ -1, 0, 0, 0, 0, 0, 1 };
    // std::cout << solution.findMedianSortedArrays(nums1, nums2) << '\n';
    return 0;
}

/*
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).


Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-10^6 <= nums1[i], nums2[i] <= 10^6
*/