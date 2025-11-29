/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& mt) {

        int n = mt.size();
        int m = mt[0].size();

        for(int i=0;i<n;i++)
        {
            reverse(mt[i].begin(), mt[i].end());
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<m;j++)
            {
                swap(mt[i][j], mt[j][i]);
            }
        }






    }
};
// @lc code=end

