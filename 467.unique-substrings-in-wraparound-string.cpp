/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 */

// @lc code=start
class Solution {
public:
    int findSubstringInWraproundString(string s) {

        vector<int> count(26, 0);
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (i > 0 && (s[i] - s[i - 1] + 26) % 26 == 1) {
                maxLength++;
            } else {
                maxLength = 1;
            }
            count[s[i] - 'a'] = max(count[s[i] - 'a'], maxLength);
        }

        int result = 0;
        for (int c : count) {
            result += c;
        }

        return result;
        
    }
};
// @lc code=end

