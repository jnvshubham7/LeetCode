/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {

        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        vector<pair<char, int>> vpos;

        for(int i=0;i<s.size();i++)
        {
            if(find(vowels.begin(), vowels.end(), s[i]) != vowels.end())
            {
                vpos.push_back({s[i], i});
            }
        }

       

        for(int i=0;i<vpos.size();i++)
        {
            s[vpos[i].second] = vpos[vpos.size() - 1 - i].first;
        }

        return s;
    }
};
// @lc code=end
