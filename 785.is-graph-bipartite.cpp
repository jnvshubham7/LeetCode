/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {

        int n = g.size();

        vector<int> color(n,-1);

        queue<int> q;

        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i] =0;
                q.push(i);


            }

            while(!q.empty())
            {
                int node = q.front();
                q.pop();

               
                for(auto ng: g[node])
                {
                    if(color[ng] == -1)
                    {
                        color[ng] = 1- color[node];
                        q.push(ng);
                    }
                    else if(color[ng]==color[node])
                    {
                        return false;
                    }
                }
            }
        }


        return true;
     





       
     
    }
};
// @lc code=end

