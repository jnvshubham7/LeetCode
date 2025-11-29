/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        unordered_map<int, int> countMap;
        vector<int> result;

        int majorityCount = nums.size() / 3;

        for(int num : nums) {
            countMap[num]++;
        }

        for(auto& pair : countMap) {
            if(pair.second > majorityCount) {
                result.push_back(pair.first);
            }
        }

        return result;

        
    }
};
// @lc code=end

