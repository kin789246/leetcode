#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<functional>

using std::vector;
using std::string;
using std::set;

void print_2d_vector(std::ofstream &ofs, const vector<vector<int>> &vec) {
    if (!ofs.is_open()) {
        std::cout << "file can't open.\n";
        return;
    }
    for (auto &v : vec) {
        for (auto i : v) {
            ofs << i << ' ';
        }
        ofs << '\n';
    }
}

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> sequence;
        set<vector<int>> result;
        std::function<void(int)> back_track = 
            [&nums, &sequence, &result, &back_track](int i) -> void {
                if (i == nums.size()) {
                    if (sequence.size() >= 2) {
                        result.insert(sequence);
                    }
                    return;
                }
                if (sequence.empty() || sequence.back()<= nums[i]) {
                    sequence.push_back(nums[i]);
                    back_track(i+1);
                    sequence.pop_back();
                }
                back_track(i+1);
            };
        back_track(0);
        return vector(result.begin(), result.end());
    }
};

int main() {
    vector<int> nums{ 4,3,2,1,1,3 };
    Solution solution;
    std::ofstream ofs("log.txt");
    print_2d_vector(ofs, solution.findSubsequences(nums));
    ofs.close();
    return 0;
}

/*
Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
0 1 2 3 4 5
4,3,2,1,1,3
i=1
4,3
i=2
4,3,2
i=3
4,3,2,1
i=4
4,3,2,1,1,1 1
i=5
4,3,2,1,1,1 1,3,1 1 3, 1 3, 1 3, 2 3, 3 3

*/