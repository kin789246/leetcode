#include<iostream>
#include<vector>

using std::vector;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mod = vector<int>(k);
        int count = 0;
        int sum = 0;
        for (auto num : nums) {
            sum += num;
            mod[((sum%k)+k)%k]++;
        }

        for (int i=0; i<k; i++) {
            if (mod[i] > 1) {
                count += (mod[i]*(mod[i]-1))/2;
            }
        }
        count += mod[0];

        return count;
    }
};

int main() {
    Solution solution;
    //vector<int> nums{ -1,2,9 };
    //int k = 2;
    vector<int> nums2{ 2, -2, 2, -4 };
    int k2 = 6;
    //std::cout << solution.subarraysDivByK(nums, k) << '\n';
    std::cout << solution.subarraysDivByK(nums2, k2) << '\n';

    return 0;
}