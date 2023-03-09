from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row, col, nxn = {}, {}, {}
        for i in range(9):
            for j in range(9):
                ni = i//3
                nj = j//3
                if board[i][j] != '.':
                    if board[i][j] in row: 
                        row[board[i][j]] += 1
                    else:
                        row[board[i][j]] = 1
                    if (j, board[i][j]) in col: 
                        col[(j, board[i][j])] += 1
                    else:
                        col[(j, board[i][j])] = 1
                    if ((ni, nj), board[i][j]) in nxn: 
                        nxn[((ni, nj), board[i][j])] += 1
                    else:
                        nxn[((ni, nj), board[i][j])] = 1
                    if row[board[i][j]] > 1 or col[(j, board[i][j])] > 1 or nxn[((ni, nj), board[i][j])] > 1:
                        return False
            row = {}
        return True
    
if __name__ == '__main__':
    s = Solution()
    board =[["5", "3", ".", ".", "7", ".", ".", ".", "."],
            ["6", ".", ".", "1", "9", "5", ".", ".", "."], 
            [".", "9", "8", ".", ".", ".", ".", "6", "."], 
            ["8", ".", ".", ".", "6", ".", ".", ".", "3"], 
            ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
            ["7", ".", ".", ".", "2", ".", ".", ".", "6"], 
            [".", "6", ".", ".", ".", ".", "2", "8", "."], 
            [".", ".", ".", "4", "1", "9", ".", ".", "5"], 
            [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
    print(s.isValidSudoku(board));
