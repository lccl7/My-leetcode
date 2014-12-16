/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //use two stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vi;
        if(root == NULL) return vi;
        stack<TreeNode*> T1, T2;
        TreeNode* cur;
        T1.push(root);
        while(!T1.empty())
        {
            cur = T1.top();
            T1.pop();
            T2.push(cur);
            if(cur->left) T1.push(cur->left);
            if(cur->right) T1.push(cur->right);
        }
        while(!T2.empty())
        {
            cur = T2.top();
            vi.push_back(cur->val);
            T2.pop();
        }
        return vi;
    }
};
