class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1000000007;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;
        int result = 0;
        
        for (int move = 1; move <= maxMove; move++) {
            vector<vector<int>> temp(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] > 0) {
                        int val = dp[i][j];
                        
                        if (i == 0) result = (result + val) % MOD;
                        else temp[i - 1][j] = (temp[i - 1][j] + val) % MOD;
                        
                        if (i == m - 1) result = (result + val) % MOD;
                        else temp[i + 1][j] = (temp[i + 1][j] + val) % MOD;
                        
                        if (j == 0) result = (result + val) % MOD;
                        else temp[i][j - 1] = (temp[i][j - 1] + val) % MOD;
                        
                        if (j == n - 1) result = (result + val) % MOD;
                        else temp[i][j + 1] = (temp[i][j + 1] + val) % MOD;
                    }
                }
            }
            dp = temp;
        }
        
        return result;
    }
};