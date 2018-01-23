class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        dp[0][0] = grid[0][0];
        
        for (int step = 1, maxStep = 2*N-2; step <= maxStep; ++step) {
        
            for (int i = min(N-1, step); i >= 0; --i) {
                if (step - i >= N) continue;
                for (int j = min(N-1, step); j >= 0; --j) {
                    if (step - j >= N || grid[i][step - i] < 0 || grid[j][step - j] < 0) {
                        dp[i][j] = -1;
                        continue;
                    }
            
                    int numCh = dp[i][j];
                    if (i > 0)  numCh = max(numCh, dp[i-1][j]);
                    if (j > 0)  numCh = max(numCh, dp[i][j-1]);
                    if (i > 0 && j > 0)  numCh = max(numCh, dp[i-1][j-1]);
                    if (numCh < 0)    continue;
                    
                    dp[i][j] =  numCh + grid[i][step-i];
                    if (i != j) dp[i][j] += grid[j][step-j];
                }
            }
        }
        return max(0, dp[N-1][N-1]);
    }
};
