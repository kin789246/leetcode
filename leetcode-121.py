from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_val = prices[0]
        ans = 0
        for p in prices:
            if p > min_val:
                ans = max(ans, p-min_val)
            else:
                min_val = min(min_val, p)
        return ans

if __name__ == '__main__':
    s = Solution()
    prices1 = [7,1,5,3,6,4]
    print(s.maxProfit(prices1))