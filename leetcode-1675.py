from typing import List
from heapq import heappop, heappush

class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        pq = []
        min_val = nums[0]*2;
        for n in nums:
            if n%2 == 1:
                n *= 2
            heappush(pq, -n)
            min_val = min(min_val, n)
        ans = -pq[0]-min_val
        while pq[0]%2 == 0:
            top_value = -heappop(pq)
            heappush(pq, -top_value//2)
            ans = min(ans, top_value-min_val)
            min_val = min(min_val, top_value//2)
        return min(ans, -pq[0]-min_val)

if __name__ == '__main__':
    solution = Solution()
    nums1 = [4, 1, 5, 20, 3] # 3
    print(solution.minimumDeviation(nums1))