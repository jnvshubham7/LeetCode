/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

  int height(TreeNode* node, int& diameter) {
     if(!node) return 0;

     int lh = height(node->left, diameter);
     int rh = height(node->right, diameter);

         // Clarification of units used in this implementation:
         //  - `height(...)` returns the height measured in NODES. A leaf node has height = 1.
         //  - `diameter` stores the maximum number of EDGES on any path between two nodes.
         //
         // For a longest path that passes through the current `node`:
         //   nodes_on_path = lh + rh + 1    (left nodes + right nodes + current node)
         //   edges_on_path = nodes_on_path - 1 = (lh + rh + 1) - 1 = lh + rh
         //
         // Therefore, when updating `diameter` (measured in edges) we use `lh + rh` (no +1).
         diameter = max(diameter, lh + rh);

         // The returned height must include the current node (measured in nodes), so add 1.
         return 1 + max(lh, rh);

        }
    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;
        height(root, diameter);
        return diameter;

        
        
    }


};
// @lc code=end

