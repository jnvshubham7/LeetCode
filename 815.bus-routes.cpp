/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

    //  dfs + bfs
        if (source == target) return 0;
        unordered_map<int, vector<int>> stop_to_buses;
        int n = routes.size();
        for (int i = 0; i < n; ++i) {
            for (int stop : routes[i]) {
                stop_to_buses[stop].push_back(i);
            }
        }

        vector<bool> visited_buses(n, false);
        queue<int> q;
        q.push(source);
        int buses_taken = 0;

        while (!q.empty()) {
            ++buses_taken;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr_stop = q.front();
                q.pop();
                for (int bus : stop_to_buses[curr_stop]) {
                    if (visited_buses[bus]) continue;
                    visited_buses[bus] = true;
                    for (int next_stop : routes[bus]) {
                        if (next_stop == target) {
                            return buses_taken;
                        }
                        q.push(next_stop);
                    }
                }
            }
        }

        return -1;

      
        
    }
};
// @lc code=end

