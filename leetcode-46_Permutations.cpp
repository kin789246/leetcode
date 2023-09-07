#include<iostream>
#include<vector>

using std::vector;
void printVector(vector<vector<int>> &v);

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        if (nums.size() == 1)
        {
            return { { nums } };
        }

        for (int i=0; i<nums.size(); i++)
        {
            int n = nums.back();
            nums.pop_back();
            vector<vector<int>> perms = permute(nums);
            //std::cout << "n=" << n << ", perms\n";
            //printVector(perms);
            for (vector<int> &perm : perms)
            {
                perm.push_back(n);
            }
            result.insert(result.end(), perms.begin(), perms.end());
            nums.insert(nums.begin(), n);
        }
        return result;
    }
};

void printVector(vector<vector<int>> &v)
{
    std::cout << "[\n";
    for (int i=0; i<v.size(); i++)
    {
        std::cout << "[";
        for (int j=0; j<v[i].size(); j++)
        {
            std::cout << v[i][j];
            if (j < v[i].size()-1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i < v.size()-1)
        {
            std:: cout << ", ";
        }
        std::cout << "\n";
    }
    std::cout << "]\n";
}

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> x = solution.permute(nums);
    printVector(x);
    return 0;
}

/*
46. Permutations
Medium
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/