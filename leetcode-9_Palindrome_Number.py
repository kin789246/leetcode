class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        reverse = 0
        num = x
        while num >= 1:
            reverse = reverse*10 + num%10
            num = num//10
            print("num = ", num, " reverse = ", reverse, '\n')
        
        return x == reverse

if __name__ == '__main__':
    solution = Solution()
    print(solution.isPalindrome(2221212))