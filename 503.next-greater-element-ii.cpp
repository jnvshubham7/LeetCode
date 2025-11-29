/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> v (nums.size()*2);

        for(int i=0; i<nums.size(); i++){
            v[i] = nums[i];
            v[i+nums.size()] = nums[i];
        }

        vector<int> res (v.size(), -1);
        stack<int> s;

        for(int i=0; i<v.size(); i++){

            while(!s.empty() && v[s.top()] < v[i]){
                res[s.top()] = v[i];
                s.pop();
            }

            s.push(i);
        }

        vector<int> ans (nums.size());

        for(int i=0; i<nums.size(); i++){
            ans[i] = res[i];
        }

        return ans;
        
        
    }
};
// @lc code=end

