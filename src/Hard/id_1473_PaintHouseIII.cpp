class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        /*
        dp[i][j][k] = minCost if houses[i]=j and there are k neighborhood remained
        
        dp[m-1][*][0] = 0   // already fit what we need. No need to paint anything
        dp[m-1][*][k] = INF // impossible to fit exactly "target" neighborhoods
        
        dp[i][j][k]
        = (A) if house[i] is initially j (house[i] == j)
                dp[i][j][k] = min(dp[i+1][j*][k - (j*==j?0:1)]) for each j*
          (B) if house[i] is initially not j
                dp[i][j][k] = INF
          (C) if house[i] is initially 0
                dp[i][j][k] = min(dp[i+1][j*][k - (j*==j?0:1)] + cost[i][j-1]) for each j*
        */
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(target+1, INT_MAX)));

        for(int j=1; j<=n; j++){
            dp[m][j][0] = 0;
        }
        
        for(int i=m-1; i>=0; i--)
        {
            for(int j=1; j<=n; j++)
            {
                if(houses[i] > 0 && houses[i] != j)
                    continue;
                
                for(int k = 1; k <= target; k++)
                {
                    for(int j2 = 1; j2 <= n; j2++)
                    {
                        dp[i][j][k] = min(dp[i][j][k], dp[i+1][j2][k - (j2==j?0:1)]);
                    }
                    
                    if(houses[i] == 0 && dp[i][j][k] < INT_MAX)
                        dp[i][j][k] += cost[i][j-1];
                }
            }
        }
        
        int result = INT_MAX;
        for(int j=1; j<=n; j++)
        {
            result = min(result, dp[0][j][target]);
        }
        return result==INT_MAX?-1:result;
    }
};

// https://leetcode.com/problems/paint-house-iii/description/
// #DP