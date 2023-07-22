#include<iostream>
#include<vector>
#include<map>
using std::cout, std::vector, std::map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out;
        map<int, int> memo;
        for (int i=0; i<nums.size(); i++) {
            int x = target - nums[i];
            if (memo.find(x) != memo.end()) {
                out.push_back(memo[x]);
                out.push_back(i);
            }
            else {
                memo[nums[i]] = i;
            }
        }
        return out;
    }
};

int main() {
    Solution s;
    vector<int> input{3, 2, 4};
    int ta = 6;
    for (auto i : s.twoSum(input, ta)) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}