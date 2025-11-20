/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalGas = 0;
        int totalCost = 0;
        int currentGas = 0;
        int startingStation = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];

            if (currentGas < 0) {
                startingStation = i + 1;
                currentGas = 0;
            }
        }

        if (totalGas < totalCost) {
            return -1;
        } else {
            return startingStation;
        }
        
    }
};
// @lc code=end

