class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if a=="0" and b=="0":
            return "0"
        da, db, carry = 0, 0, 0
        ans = ""
        ia, ib = len(a)-1, len(b)-1
        while True:
            if ia<0 and ib<0:
                break
            if ia<0:
                da = 0
            else:
                da = 0 if a[ia]=='0' else 1
            if ib<0:
                db = 0
            else:
                db = 0 if b[ib]=='0' else 1
            tmp = da + db + carry
            if tmp == 0:
                carry = 0
                ans = '0' + ans
            elif tmp == 1:
                carry = 0
                ans = '1' + ans
            elif tmp == 2:
                carry = 1
                ans = '0' + ans
            else:
                carry = 1
                ans = '1' + ans
            ia -= 1
            ib -= 1
        
        if carry == 1:
            ans = '1' + ans

        return ans
    
if __name__ == '__main__':
    solution = Solution()
    a = "1010"
    b = "1011" # Output: "10101"
    print(solution.addBinary(a, b))