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
    // Approach 1: Recursive DFS
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateHeight(root, diameter);
        return diameter;
    }

private:
    int calculateHeight(TreeNode* node, int& diameter) {
        if (!node) return 0;

        int leftHeight = calculateHeight(node->left, diameter);
        int rightHeight = calculateHeight(node->right, diameter);

        diameter = std::max(diameter, leftHeight + rightHeight);

        return 1 + std::max(leftHeight, rightHeight);
    }

    // Approach 2: Iterative DFS Using Stack
    int diameterOfBinaryTreeIterative(TreeNode* root) {
        if (!root) return 0;

        std::stack<TreeNode*> stack;
        std::unordered_map<TreeNode*, int> heightMap;
        int diameter = 0;

        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();

            if (node->left && heightMap.find(node->left) == heightMap.end()) {
                stack.push(node->left);
            } else if (node->right && heightMap.find(node->right) == heightMap.end()) {
                stack.push(node->right);
            } else {
                stack.pop();
                int leftHeight = node->left ? heightMap[node->left] : 0;
                int rightHeight = node->right ? heightMap[node->right] : 0;
                heightMap[node] = 1 + std::max(leftHeight, rightHeight);
                diameter = std::max(diameter, leftHeight + rightHeight);
            }
        }

        return diameter;
    }

    // Approach 3: Breadth-First Search (BFS)
    int diameterOfBinaryTreeBFS(TreeNode* root) {
        if (!root) return 0;

        std::queue<TreeNode*> queue;
        std::unordered_map<TreeNode*, int> heightMap;
        int diameter = 0;

        queue.push(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();

            int leftHeight = node->left ? heightMap[node->left] : 0;
            int rightHeight = node->right ? heightMap[node->right] : 0;

            diameter = std::max(diameter, leftHeight + rightHeight);

            if (node->left) queue.push(node->left);
            if (node->right) queue.push(node->right);
        }

        return diameter;
    }

    // Approach 4: Postorder Traversal with Memoization
    int diameterOfBinaryTreeMemo(TreeNode* root) {
        std::unordered_map<TreeNode*, int> memo;
        int diameter = 0;
        calculateHeightMemo(root, diameter, memo);
        return diameter;
    }

    int calculateHeightMemo(TreeNode* node, int& diameter, std::unordered_map<TreeNode*, int>& memo) {
        if (!node) return 0;
        if (memo.find(node) != memo.end()) return memo[node];

        int leftHeight = calculateHeightMemo(node->left, diameter, memo);
        int rightHeight = calculateHeightMemo(node->right, diameter, memo);

        diameter = std::max(diameter, leftHeight + rightHeight);
        memo[node] = 1 + std::max(leftHeight, rightHeight);
        return memo[node];
    }

    // Approach 5: Dynamic Programming on Trees
    int diameterOfBinaryTreeDP(TreeNode* root) {
        std::unordered_map<TreeNode*, int> dp;
        int diameter = 0;
        calculateHeightDP(root, diameter, dp);
        return diameter;
    }

    int calculateHeightDP(TreeNode* node, int& diameter, std::unordered_map<TreeNode*, int>& dp) {
        if (!node) return 0;
        if (dp.find(node) != dp.end()) return dp[node];

        int leftHeight = calculateHeightDP(node->left, diameter, dp);
        int rightHeight = calculateHeightDP(node->right, diameter, dp);

        diameter = std::max(diameter, leftHeight + rightHeight);
        dp[node] = 1 + std::max(leftHeight, rightHeight);
        return dp[node];
    }
};
// @lc code=end

