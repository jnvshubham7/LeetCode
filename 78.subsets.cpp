/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> res;
        vector<int> path;



        rec(0, n, nums, path, res);
        return res;
 
    }

    void rec(int start, int n, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {

        // res.push_back(path);

        // for (int i = start; i < n; ++i) {

        //     path.push_back(nums[i]);
        //     rec(i + 1, n, nums, path, res);
        //     path.pop_back();

        // }

        res.push_back(path);

        for(int i= start;i<n;i++)
        {
            path.push_back(nums[i]);
            rec(i + 1, n, nums, path, res);
            path.pop_back();
        }

        

    }


};
// @lc code=end

