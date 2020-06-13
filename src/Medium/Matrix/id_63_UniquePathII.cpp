class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1)
            return 0;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                obstacleGrid[i][j] = obstacleGrid[i][j]==1? -1:0;
        
        obstacleGrid[0][0] = 1;
        
        return _uniquePaths(obstacleGrid, m-1, n-1);
    }
    
    int _uniquePaths(vector<vector<int>>& history, int m, int n)
    {
        if(m < 0 || n < 0)
            return 0;
        
        if(history[m][n] == -1)
            return 0;
        
        if(history[m][n] > 0)
            return history[m][n];
        
        history[m][n] = _uniquePaths(history, m-1, n) + _uniquePaths(history, m, n-1);
        return history[m][n];
    }
};

// https://leetcode.com/problems/unique-paths-ii/description/
// #DP