/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {


        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                std::swap(maxProd, minProd);
            }

            maxProd = std::max(nums[i], maxProd * nums[i]);
            minProd = std::min(nums[i], minProd * nums[i]);

            result = std::max(result, maxProd);
        }

        return result;
        
    }
};
// @lc code=end

