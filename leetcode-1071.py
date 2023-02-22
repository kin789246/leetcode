import math
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1+str2 != str2+str1:
            return ""
        gcd_base_len = math.gcd(len(str1), len(str2))
        return str1[0:gcd_base_len]


if __name__ == '__main__':
    solution = Solution()
    str1 = "ABABAB"
    str2 = "ABAB"
    print(solution.gcdOfStrings(str1,str2))