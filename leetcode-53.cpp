#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local_max = nums[0];
        int max = nums[0];
        for (int i=1; i<nums.size(); i++) {
            local_max = std::max(nums[i], local_max+nums[i]);
            max = std::max(max, local_max);
        }
        return max;
    }
};

int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution solution;
    std::cout << solution.maxSubArray(nums) << '\n';

    return 0;
}