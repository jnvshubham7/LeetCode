/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, 0, combination, result);
        return result;
        
    }

    void backtrack(const vector<int>& candidates, int target, int start,
                   vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, combination, result);
            combination.pop_back();
        }
    }
};
// @lc code=end

