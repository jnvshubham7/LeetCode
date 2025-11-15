/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;      // avoid mod by zero
        k = k % n;
        if (k == 0) return;

        // // reverse whole array, then first k, then remaining n-k
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        // int n = nums.size();
        // k = k %n;
        // for(int i=0; i<k;i++)
        // {
        //     int last = nums[n-1];
        //     for(int j=n-1;j>0;j--)
        //     {
        //         nums[j] = nums[j-1];

        //     }
        //   nums[0] = last;







        // }
    }
};
// @lc code=end

