from queue import Queue
class Solution:
    def maxDistance(self, grid: list[list[int]]) -> int:
        n = len(grid)
        directions = {(0,1), (0,-1), (-1,0), (1,0)}
        q = Queue()
        distance = -1
        visited = [[0 for i in range(n)] for i in range(n)]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    visited[i][j] = grid[i][j]
                    q.put((i,j))
        if q.qsize()==0 or q.qsize()==n*n:
            return -1
        while q.empty() == False:
            q_size = q.qsize()
            while q_size != 0:
                q_size -= 1
                land_cell = q.get()
                for d in directions:
                    x = land_cell[0] + d[0]
                    y = land_cell[1] + d[1]
                    if x>=0 and x<n and y>=0 and y<n and visited[x][y]==0:
                        if grid[x][y] == 0:
                            visited[x][y] = 1
                            grid[x][y] = 1
                            q.put((x,y))
                
            distance += 1

        return distance if distance!=0 else -1

if __name__ == '__main__':
    solution = Solution()
    g1 = [[1, 0, 1], [0, 0, 0], [1, 0, 1]]
    print(solution.maxDistance(g1))
