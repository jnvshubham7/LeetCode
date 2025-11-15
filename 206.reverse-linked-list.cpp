/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {

            

        }

        // ListNode* prev = nullptr;
        // ListNode* curr = head;

        // while(curr != nullptr){
        //     ListNode* nextTemp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nextTemp;
        // }

        // return prev;

        // iterative approach
        // time complexity : O(n)
        // space complexity : O(1)

        // can we do this recursively?
        // yes we can do this recursively
        // but the space complexity will be O(n) for recursion stack
        
    }
};
// @lc code=end

