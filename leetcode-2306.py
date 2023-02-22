class Solution:
    def distinctNames(self, ideas: list[str]) -> int:
        suffix_table = [set() for i in range(0, 26)]
        for idea in ideas:
            suffix_table[ord(idea[0])-ord('a')].add(idea[1:])
        ans = 0
        for i in range(25):
            for j in range(i+1, 26):
                mutual = 0
                for suffixes_i in suffix_table[i]:
                    if suffixes_i in suffix_table[j]:
                        mutual += 1
                ans += (len(suffix_table[i])-mutual) * (len(suffix_table[j])-mutual)
        return ans*2

if __name__ == '__main__':
    solution = Solution()
    i1 = ["coffee", "donuts", "time", "toffee"]
    print(solution.distinctNames(i1))
