# Leetcode problem 6 ZigZag Conversion
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 1:
            return s
        
        direction = -1 #-1 = go down, 1 = go up
        lv = numRows - 1
        zigzag = []
        # init zigzag
        for i in range(0, numRows):
            zigzag.append([])
        
        for i in range(0, len(s)):
            zigzag[lv].append(s[i])
            lv = lv + direction
            if lv == numRows:
                lv = numRows - 2
                direction = -1
            if lv < 0:
                lv = 1
                direction = 1
        
        return "".join(["".join(i) for i in zigzag[::-1]])

if __name__ == "__main__":
    s = "PAYPALISHIRING"
    s1 = "AB"
    ans = Solution()
    print(ans.convert(s, 3))
    print(ans.convert(s1, 1))

'''
        P   H
        A  SI
        Y I R
        PL  IG
        A   N

        P   A   H   N
        A P L S I I G
        Y   I   R

        P     I    N
        A   L S  I G
        Y A   H R
        P     I
'''