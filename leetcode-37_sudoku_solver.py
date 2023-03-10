from typing import List

def print_board(b):
    for row in b:
        print(' '.join(row))

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        def is_valid(r, c, ch):
            for i in range(9):
                if board[r][i] == ch:
                    return False
                if board[i][c] == ch:
                    return False
                if board[3*(r//3)+i//3][3*(c//3)+i%3] == ch:
                    return False
            return True
        
        def solve():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == '.':
                        for x in ['1','2','3','4','5','6','7','8','9']:
                            if is_valid(i, j, x) == True:
                                board[i][j] = x
                                if solve() == True:
                                    return True
                                board[i][j] = '.'
                        return False
            return True
        solve()

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
    print_board(board)
    print()
    s.solveSudoku(board);
    print_board(board)
