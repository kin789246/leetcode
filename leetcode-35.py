from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        s, e = 0, len(nums)-1
        while s <= e:
            m = (s + e) // 2
            if nums[m] == target:
                return m
            if nums[m] < target:
                s = m + 1
            else:
                e = m - 1
        return s

if __name__ == '__main__':
    s = Solution()
    nums = [1,3,5,6]
    target = 5
    print(s.searchInsert(nums, target))