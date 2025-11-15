/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {

    //    unordered_map<int, int> countMap;

    //      int majorityCount = nums.size() / 2;

    //    for(int num : nums) {
    //        countMap[num]++;
    //           if(countMap[num] > majorityCount) {
    //             return num;
    //           }  
    //    }

//    tell me tc and sc of above approach
//   // TC: O(n) - We traverse the list of numbers once to count occurrences, where n is the number of elements in nums.
//   // SC: O(k) - In the worst case, we may store counts for all unique elements in the hashmap, where k is the number of unique elements in nums.

// new optmized approach using Boyer-Moore Voting Algorithm

       int count = 0;
       int candidate = 0;

       for (int num : nums) {
           if (count == 0) {
               candidate = num;
           }
           count += (num == candidate) ? 1 : -1;
       }

       return candidate;

      

    //    return -1; // This line should never be reached given the problem constraints


        
    }
};
// @lc code=end

