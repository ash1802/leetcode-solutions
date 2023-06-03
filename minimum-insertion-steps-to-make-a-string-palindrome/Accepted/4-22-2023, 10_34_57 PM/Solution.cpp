// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

class Solution {
public:
    
    int solve(string &s, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        // if character matches at i and j
        if(s[i] == s[j]) return dp[i][j] = solve(s,i+1,j-1,dp);

        // character does not match at i and j so we either insert at i or at j and then try to form palindrome
        else return dp[i][j] = 1 + min(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    }

    int minInsertions(string s) 
    {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,0,n-1, dp);
    }
};