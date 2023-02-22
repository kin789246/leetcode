class Solution:
    def tribonacci(self, n: int) -> int:
        if n <= 0:
            return 0
        if n==1 or n==2:
            return 1
        sum = 0
        nn3, nn2, nn1 = 0, 1, 1
        for i in range(3,n+1):
            sum = nn3 + nn2 + nn1
            nn3 = nn2
            nn2 = nn1
            nn1 = sum
        return sum


if __name__ == '__main__':
    solution = Solution()
    print(solution.tribonacci(25))
