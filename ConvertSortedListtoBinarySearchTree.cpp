/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        TreeNode *root;
        if(head == NULL) return root;
        if(head->next == NULL)
        {
            root = new TreeNode(head->val);
            return root;
        }
        ListNode *pre = NULL, *fast = head, *slow = head;
        while(fast->next && fast->next->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        root = new TreeNode(slow->val);
        if(pre)
        {
            pre->next = NULL;
            root->left = sortedListToBST(head);
        }
        root->right = sortedListToBST(fast);
        return root;
    }
};
