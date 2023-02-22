class Solution:
    def bestTeamScore(self, scores: list[int], ages: list[int]) -> int:
        age_score = list(zip(ages, scores))
        age_score.sort()
        ans = 0
        dp = [x[1] for x in age_score]
        ans = max(dp)
        for i in range(len(scores)):
            for j in range(i-1, -1, -1):
                if age_score[i][1] >= age_score[j][1]:
                    dp[i] = max(dp[i], age_score[i][1]+dp[j])
            ans = max(dp[i], ans)
        
        return ans

if __name__ == '__main__':
    solution = Solution()
    s1 = [1,3,5,10,15]
    a1 = [1,2,3,4,5]
    s2 = [4,5,6,5]
    a2 = [2,1,2,1]
    s3 = [1,2,3,5]
    a3 = [8,9,10,1]
    print(solution.bestTeamScore(s1, a1))
    print(solution.bestTeamScore(s2, a2))
    print(solution.bestTeamScore(s3, a3))