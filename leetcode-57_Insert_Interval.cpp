#include<iostream>
#include<vector>
#include<queue>

using std::vector;

void printVector(const vector<int> &v) {
    std::cout << "v -> ";
    for (auto &i : v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> r;
        if (intervals.size() == 0) {
            r.push_back({newInterval});
            return r;
        }
        for (auto it=intervals.begin(); it!=intervals.end(); it++) {
            if ((*it)[0] > newInterval[0]) {
                intervals.insert(it,newInterval);
                break;
            }
            if (it+1 == intervals.end()) {
                intervals.push_back(newInterval);
                break;
            }
        }
        vector<int> temp{intervals[0]};
        auto it = intervals.begin();
        it++;
        while (it!=intervals.end()) {
            if (temp[1] < (*it)[0]) {
                r.push_back(temp);
                temp = (*it);
            }
            else if (temp[1] >= (*it)[0]) {
                if (temp[1] <= (*it)[1])
                    temp = vector<int>{temp[0], (*it)[1]};
            }
            it++;
        }
        r.push_back(temp);
        return r;
    }
};

int main() {
    Solution s;
    //vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4,8};
    //s.insert(intervals,newInterval);
    vector<vector<int>> intervals2{{1,5}};
    newInterval = {2,7};
    s.insert(intervals2,newInterval);
    return 0;
}

/*
    Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    Output: [[1,2],[3,10],[12,16]]
    Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/