/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:

  


    int uniquePaths(int m, int n) {

        int cnt =0;

        return helper(0,0,m,n,cnt);
        // thsi will give tle for large inputs
        // because of overlapping subproblems
        // time complexity : O(2^(m+n))
        // why this time complexity?
        // because at each cell we have 2 choices either go down or go right
        // 19
        // 13
        // why give tle in this approach?
        // because of overlapping subproblems
        // do dry for this value m = 19 n = 13

        // space complexity : O(m+n) for recursion stack

        // can we optimize this approach?
        // can we use memoization?
        // yes we can use memoization to store the results of subproblems
        // and reuse them when needed
        // this will reduce the time complexity to O(m*n)
        // and space complexity to O(m*n) for dp array + O(m+n) for recursion stack
        




        
    }

    int helper(int i, int j, int m, int n, int &cnt){

        if(i==m-1 && j==n-1){

            return 1;

        }

        if(i>=m || j>=n){

            return 0;

        }

        return helper(i+1,j,m,n,cnt) + helper(i,j+1,m,n,cnt);

        // why giviing tle?
        // because of overlapping subproblems


        

    }
};
// @lc code=end

