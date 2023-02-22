class Solution:
    def isAlienSorted(self, words: list[str], order: str) -> bool:
        order_map = {}
        for i in range(0,26):
            order_map[order[i]]=i
        for i in range(len(words)-1):
            cur = 0
            while cur < len(words[i]):
                if cur >= len(words[i+1]):
                    return False
                if order_map[words[i][cur]] < order_map[words[i+1][cur]]:
                    break
                if order_map[words[i][cur]] > order_map[words[i+1][cur]]:
                    return False
                cur+=1
        return True

if __name__ == '__main__':
    solution = Solution()
    w1 = ["word","world","row"]
    o1 = "worldabcefghijkmnpqstuvxyz"
    print(solution.isAlienSorted(w1,o1))