from typing import List

class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def fesible(capacity:int) -> bool:
            sum = 0
            days_needed = 1
            for w in weights:
                sum += w
                if sum > capacity:
                    sum = w
                    days_needed += 1
                    if days_needed > days:
                        return False
            return True
        
        total_load, max_load = 0, 0
        for w in weights:
            total_load += w;
            max_load = max(max_load, w)
        left, right = max_load, total_load
        while left < right:
            middle = left + (right-left)//2
            if fesible(middle):
                right = middle
            else:
                left = middle+1
        return left

if __name__ == '__main__':
    solution = Solution()
    w1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    d1 = 5
    print(solution.shipWithinDays(w1, d1))