/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {

        // 435383 -> 435838
        // 41232 -> 41322
        // 2
        // write 10 exmples and find pattern
        // 


        string s = to_string(n);
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        



        
    }
};
// @lc code=end

