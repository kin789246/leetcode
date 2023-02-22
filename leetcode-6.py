import math
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows == len(s):
            return s
        direct = 1
        r = 0
        cur = 0
        zigzag_table = [""]*numRows
        while cur != len(s):
            zigzag_table[r] += s[cur]
            if r==0:
                direct = 1
            if r==numRows-1:
                direct = -1
            r += direct
            cur += 1

        return "".join(zigzag_table)


if __name__ == '__main__':
    solution = Solution()
    s1 = "PAYPALISHIRING"
    n1 = 3
    print(solution.convert(s1,n1)) # "PAHNAPLSIIGYIR"