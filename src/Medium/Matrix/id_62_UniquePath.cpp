class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<n)
            return uniquePaths(n,m);
        
        m = m - 1;
        n = n - 1;
        
        double result = 1;
        
        // (m+n)!/(m!)(n!)        
        for(int i=0; i<n; i++){
            result = result * (m+n-i)/(double)(i+1);
        }
        return (int)result;
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> history(m, vector<int>(n,0));
        history[0][0] = 1;
        
        return _uniquePaths(history, m-1, n-1);
    }
    
    int _uniquePaths(vector<vector<int>>& history, int m, int n)
    {
        if(m < 0 || n < 0)
            return 0;
        
        if(history[m][n] > 0)
            return history[m][n];
        
        history[m][n] = _uniquePaths(history, m-1, n) + _uniquePaths(history, m, n-1);
        return history[m][n];
    }
};

// https://leetcode.com/problems/unique-paths/description/
// #DP #math