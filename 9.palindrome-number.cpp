/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers are not palindromes
        if (x < 0) return false;

        // Convert the integer to string
        string str = to_string(x);
        int left = 0;
        int right = str.size() - 1;

        // Check for palindrome by comparing characters from both ends
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;

        
        
    }
};
// @lc code=end

