/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // two things should be paid attention:
 // 1. if one of the child is null, while the other not, you should return the other
 // because it has not reached the leaf.
 // 2. the last condition should be plus one(that is the root).
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        else if(root->left == NULL && root->right)
            return 1 + minDepth(root->right);
        else if(root->right == NULL && root->left) 
            return 1 + minDepth(root->left);
        else
        {
            int ml = minDepth(root->left);
            int mr = minDepth(root->right);
            return ml < mr ? ml+1 : mr+1;
        }
    }
};
