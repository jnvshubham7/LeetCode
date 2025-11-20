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

       
};
// @lc code=end

