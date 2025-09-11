/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices out of the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            // Remove indices whose corresponding values are less than nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            // The front of the deque is the largest element's index
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};
// @lc code=end

