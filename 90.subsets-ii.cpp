/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {


        sort(nums.begin(), nums.end());

        set<vector<int>> res_set;
        vector<int> path;
        rec(0, nums.size(), nums, path, res_set);

        vector<vector<int>> res(res_set.begin(), res_set.end());
        return res;
    }

    void rec(int start, int n, vector<int>& nums, vector<int>& path, set<vector<int>>& res_set) {

        res_set.insert(path);

        for(int i= start;i<n;i++)
        {
            path.push_back(nums[i]);
            rec(i + 1, n, nums, path, res_set);
            path.pop_back();
        }
    }
};
// @lc code=end

