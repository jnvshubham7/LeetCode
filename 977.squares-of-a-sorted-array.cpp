/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        // in thsi why we will nto used sort function because it will take O(nlogn) time complexity
        //  we will use two pointer approach to solve this problem in O(n) time complexity
        int n = nums.size();
        vector<int> res(n);
        int left = 0;
        int right = n - 1;
        int index = n - 1;

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if (leftSquare > rightSquare) {
                res[index] = leftSquare;
                left++;
            } else {
                res[index] = rightSquare;
                right--;
            }
            index--;
        }

        return res;
    }
};
// @lc code=end

