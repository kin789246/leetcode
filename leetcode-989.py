import math
class Solution:
    def addToArrayForm(self, num: list[int], k: int) -> list[int]:
        carry = 0
        for i in range(len(num)-1, -1, -1):
            num[i] = carry + k%10 + num[i]
            carry = num[i] // 10
            num[i] = num[i] % 10
            k = k // 10
            if k==0 and carry==0:
                break
        if k != 0:
            k += carry
            carry = 0
        while k != 0:
            num.insert(0, k%10)
            k = k // 10
            
        if carry != 0:
            num.insert(0, carry)
        return num


if __name__ == '__main__':
    solution = Solution()
    n1 = [1, 2, 0, 0] 
    k1 = 34
    print(solution.addToArrayForm(n1, k1)) # 1234