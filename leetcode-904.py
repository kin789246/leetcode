class Solution:
    def totalFruit(self, fruits: list[int]) -> int:
        n = len(fruits)
        if n < 2:
            return n
        l,r = 0,1
        type_no = {}
        type_no[fruits[l]] = 1
        max_picks = 2
        while l<n and r<n:
            if fruits[r] in type_no:
                type_no[fruits[r]] += 1
            else:
                type_no[fruits[r]] = 1
            r += 1
            if len(type_no.keys()) > 2:
                if type_no[fruits[l]] <= 1:
                    type_no.pop(fruits[l])
                else:
                    type_no[fruits[l]] -= 1
                l += 1
            max_picks = max(max_picks, r-l)
        return max_picks

if __name__ == '__main__':
    solution = Solution()
    f1 = [1,2,1]
    print(solution.totalFruit(f1))
    f2 = [0,1,2,2]
    print(solution.totalFruit(f2))
    f3 = [1,2,3,2,2]
    print(solution.totalFruit(f3))