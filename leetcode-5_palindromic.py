class Solution:
    def longestPalindrome(self, s: str) -> str:
        def check(l, r):
            while 0<=l and r<len(s):
                if s[r] == s[l]:
                    l-=1
                    r+=1
                else:
                    break
            return s[l+1:r]
        max_len = 1
        ans = s[0]
        for i in range(len(s)):
            s1 = check(i, i)
            s2 = check(i, i+1)
            if max_len < len(s1):
                max_len = len(s1)
                ans = s1
            if max_len < len(s2):
                max_len = len(s2)
                ans = s2
        return ans

if __name__ == '__main__':
    solution = Solution()
    s1 = 'cbbd'
    print(solution.longestPalindrome(s1))
    s1 = 'aaaa'
    print(solution.longestPalindrome(s1))