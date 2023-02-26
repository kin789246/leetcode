class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp = [[0 for x in range(len(word1)+1)] for y in range(len(word2)+1)]
        for i in range(len(dp)):
            for j in range(len(dp[0])):
                if i == 0:
                    dp[i][j] = j
                elif j == 0:
                    dp[i][j] = i
                elif word1[j-1] == word2[i-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
        return dp[-1][-1]

if __name__ == '__main__':
    s = Solution()
    word1 = "horse"
    word2 = "ros"
    print(s.minDistance(word1, word2))