/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node to be deleted found
            if (!root->left) {
                return root->right;
            } else if (!root->right) {
                return root->left;
            } else {
                // Node with two children: Get the inorder successor (smallest in the right subtree)
                TreeNode* successor = root->right;
                while (successor->left) {
                    successor = successor->left;
                }
                // Copy the inorder successor's value to this node
                root->val = successor->val;
                // Delete the inorder successor
                root->right = deleteNode(root->right, successor->val);


                // explain above part prpoper 
                // why we need to find the inorder successor?
                // In a binary search tree (BST), the inorder successor of 
                // a node is the node with the smallest value that is greater than the value of the given node.
                // When deleting a node with two children, we need to maintain the properties of the BST
                // To do this, we can replace the value of the node to be deleted with the value of its inorder successor.
                // This ensures that all values in the left subtree remain less than the new value of the node,
                // and all values in the right subtree remain greater than the new value of the node.   
                


            }
        }
        return root;

     
        
    }
};
// @lc code=end

