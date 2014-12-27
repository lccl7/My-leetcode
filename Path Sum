/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // If no if(!root) statement in the function hasPathSum, runtime is 4ms longer.
 //the second solution is to use non-recursive method, but time is 32ms longer
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        return dfs(root, sum, 0);
    }
    bool dfs(TreeNode *root, int sum, int now)
    {
        if(!root) return false;
        else if(sum == now + root->val && !root->left && !root->right) return true;
        else 
        {
            return dfs(root->left, sum, now + root->val) || dfs(root->right, sum, now + root->val);
        }
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) 
            return false;
        queue<TreeNode*> qtree;
        queue<int> qint;
        qtree.push(root); qint.push(root->val);
        while(!qtree.empty())
        {
            TreeNode *t = qtree.front(); qtree.pop();
            int s = qint.front(); qint.pop();
            if(s == sum && !t->left && !t->right)
                return true;
            if(t->left)
                {
                    qtree.push(t->left);
                    qint.push(s+t->left->val);
                }
            if(t->right)
                {
                    qtree.push(t->right);
                    qint.push(s+t->right->val);
                }
        }
        return false;
    }
};
