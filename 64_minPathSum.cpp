class Solution{
    public:
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        if (m == 0) return 0; 
        int n = grid[0].size();
        vector<vector<int>> minPath(m, vector<int>(n, -1)); // notice 
        return minPathSum(grid, m-1, n-1, minPath); 
    }
    private:
    int minPathSum(vector<vector<int>>& grid, int x, int y, 
                    vector<vector<int>>& minPath){
        if (x == 0 && y == 0) return grid[0][0]; 
        if (x < 0 || y < 0) return INT_MAX; 
        if (minPath[x][y] > -1) return minPath[x][y]; 
    
        minPath[x][y] = grid[x][y] + min(minPathSum(grid, x-1, y, minPath), 
                        minPathSum(grid, x, y-1, minPath));
        return minPath[x][y]; 
    }
};