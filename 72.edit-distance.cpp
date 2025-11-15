/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {

        // give me approch 

        int m = word1.size();
        int n = word2.size();

        // use recussion with memoization
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(word1, word2, m, n, dp);



        
        
    }

    int helper(string &word1, string &word2, int m, int n, vector<vector<int>> &dp){

        // base case
        if(m==0) return n; // insert all n characters
        if(n==0) return m; // delete all m characters

        if(dp[m][n] != -1) return dp[m][n];

        if(word1[m-1] == word2[n-1]){
            return dp[m][n] = helper(word1, word2, m-1, n-1, dp);
        }
        else{
            // insert
            int insertOp = 1 + helper(word1, word2, m, n-1, dp);
            // delete
            int deleteOp = 1 + helper(word1, word2, m-1, n, dp);
            // replace
            int replaceOp = 1 + helper(word1, word2, m-1, n-1, dp);

            return dp[m][n] = min(insertOp, min(deleteOp, replaceOp));
        }
};
// @lc code=end

