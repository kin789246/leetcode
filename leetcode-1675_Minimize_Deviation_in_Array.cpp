#include<iostream>
#include<vector>
#include<queue>

using std::vector, std::priority_queue;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans, min_value=nums[0]*2;
        priority_queue<int> pq;
        for (auto n : nums) {
            if (n%2 == 1) {
                n = n*2;
            }
            pq.push(n);
            min_value = std::min(min_value, n);
        }
        ans = pq.top() - min_value;
        while (pq.top()%2 == 0) {
            int top_value = pq.top();
            pq.pop();
            ans = std::min(ans, top_value - min_value);
            pq.push(top_value / 2);
            min_value = std::min(min_value, top_value/2);
        }
        return std::min(ans, pq.top()-min_value);
    }
};

int main() {
    Solution s;
    vector<int> n1{ 1, 2, 3, 4 }; // 1
    std::cout << s.minimumDeviation(n1) << '\n';
    vector<int> n2{ 4, 1, 5, 20, 3 }; // 3
    std::cout << s.minimumDeviation(n2) << '\n';
    vector<int> n3{ 2, 10, 8 }; // 3
    std::cout << s.minimumDeviation(n3) << '\n';
    return 0;
}

/*
1675. Minimize Deviation in Array

You are given an array nums of n positive integers.
You can perform two types of operations on any element of the array any number of times:
If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.


Example 1:

Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.

Example 2:

Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.

Example 3:

Input: nums = [2,10,8]
Output: 3


Constraints:

n == nums.length
2 <= n <= 5 * 10^4
1 <= nums[i] <= 10^9
*/