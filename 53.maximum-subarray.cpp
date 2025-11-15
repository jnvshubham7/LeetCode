/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ms = nums[0];
        int cs = 0;

        for (int n : nums)
        {
            cs += n;
            if(cs > ms) 
            ms = cs;
        if(cs < 0) 
            cs = 0;
        }
        return ms;
    }
};
// @lc code=end

