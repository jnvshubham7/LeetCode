/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& mm) {

        int n  = mm.size();
        int m = mm[0].size();

       vector<bool> row(n, false);
       vector<bool> col(m, false);
         for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                if(mm[i][j]==0){
                     row[i]=true;
                     col[j]=true;
                }
              }
         }

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(row[i] || col[j]){
                        mm[i][j]=0;
                    }
                }
            }








        
    }
};
// @lc code=end

