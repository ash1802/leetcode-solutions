// https://leetcode.com/problems/unique-paths

class Solution {
public:
    // recursion + memoization solution here
    int solve(int i, int j, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(i, j-1, dp);
        int up = solve(i-1, j, dp);
        
        return dp[i][j] = left + up;
    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // // return solve(m-1,n-1, dp);
        
        // // tabulation solution here, top-down approach followed
        // dp[0][0] = 1;
        // for(int i=0; i<m; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(i > 0) dp[i][j] += dp[i-1][j];
        //         if(j > 0) dp[i][j] += dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];

        // space optimisation here
        // if there is usage of previous row and previous column
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++) {
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0) temp[j] = 1;
                else {
                    if(i > 0) temp[j] += prev[j];
                    if(j > 0) temp[j] += temp[j-1];
                }
            }
            prev = temp;
        }

        return prev[n-1];
    }
};