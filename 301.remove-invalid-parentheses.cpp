/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {


        vector<string> res;
        int leftRemove =0;
        int rightRemove =0;

        for(char c: s)
        {
            if(c == '(')
            {
                leftRemove++;
            }
            else if(c == ')')
            {
                if(leftRemove ==0)
                {
                    rightRemove++;
                }
                else
                {
                    leftRemove--;
                }
            }
        }

        function<void(int, int, int, int, string)> backtrack = [&](int index, int leftCount, int rightCount, int leftRem, int rightRem, string path)
        {
            if(index == s.size())
            {
                if(leftRem ==0 && rightRem ==0)
                {
                    res.push_back(path);
                }
                return;
            }

            char c = s[index];

            if(c == '(' && leftRem >0)
            {
                backtrack(index +1, leftCount, rightCount, leftRem -1, rightRem, path);
            }
            else if(c == ')' && rightRem >0)
            {
                backtrack(index +1, leftCount, rightCount, leftRem, rightRem -1, path);
            }

            path.push_back(c);

            if(c != '(' && c != ')')
            {
                backtrack(index +1, leftCount, rightCount, leftRem, rightRem, path);
            }
            else if(c == '(')
            {
                backtrack(index +1, leftCount +1, rightCount, leftRem, rightRem, path);
            }
            else if(c == ')' && leftCount > rightCount)
            {
                backtrack(index +1, leftCount, rightCount +1, leftRem, rightRem, path);
            }

        };

        backtrack(0, 0, 0, leftRemove, rightRemove, "");

        return res;


        
    }
};
// @lc code=end

