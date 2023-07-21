#include<iostream>

class Solution {
public:
    int tribonacci(int n) {
        int sum=0;
        if (n<=0) return 0;
        if (n==1 || n==2) return 1;
        int nn3=0, nn2=1, nn1=1;
        for (int i=3; i<=n; i++) {
            sum = nn3 + nn2 + nn1;
            nn3 = nn2;
            nn2 = nn1;
            nn1 = sum;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    std::cout << solution.tribonacci(25) << '\n';

    return 0;
}