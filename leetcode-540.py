from sys import maxsize
from typing import List

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        s, e = 0, len(nums)-1
        while s < e:
            m = (s+e)//2
            if m % 2 == 0:
                if nums[m] != nums[m+1]:
                    e = m
                else:
                    s = m+1
            else:
                if nums[m] == nums[m+1]:
                    e = m
                else:
                    s = m+1
        return nums[s]

if __name__ == '__main__':
    s = Solution()
    n1 = [1, 1, 2] # 2
    print(s.singleNonDuplicate(n1))
    n2 = [1, 1, 2, 3, 3]  # 2
    print(s.singleNonDuplicate(n2))

