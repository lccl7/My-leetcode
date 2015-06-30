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
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        else return false;
    }
    int height(TreeNode *root)
    {
        if(root == NULL) return 0;
        else return 1 + max(height(root->left), height(root->right));
    }
};
