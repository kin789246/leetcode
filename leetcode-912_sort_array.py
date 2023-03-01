from typing import List

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge_sort(l, r):
            if l >= r:
                return
            m = l + (r-l)//2
            merge_sort(l, m)
            merge_sort(m+1, r)
            merge(l, r, m)

        def merge(l, r, m):
            il, ir = l, m+1
            auxiliary = []
            while il<=m and ir<=r:
                if nums[il] < nums[ir]:
                    auxiliary.append(nums[il])
                    il += 1
                else:
                    auxiliary.append(nums[ir])
                    ir += 1
            
            while il <= m:
                auxiliary.append(nums[il])
                il += 1
            
            while ir <= r:
                auxiliary.append(nums[ir])
                ir += 1

            for n in auxiliary:
                nums[l] = n
                l += 1

        merge_sort(0, len(nums)-1)
        return nums

if __name__ == '__main__':
    s = Solution()
    nums1 = [5,1,1,2,0,0]
    print(s.sortArray(nums1))

