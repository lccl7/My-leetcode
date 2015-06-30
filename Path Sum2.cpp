/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //pay attention to the pop_back()
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        vector<int> vi;
        dfs(root, sum, 0, res, vi);
        return res;
    }
    void dfs(TreeNode *root, int sum, int now, vector<vector<int>> &res, vector<int> &vi)
    {
        if(!root) return;
        now += root->val;
        vi.push_back(root->val);
        if(root->left == NULL && root->right == NULL && sum == now)
        {
            res.push_back(vi);
        }
        if(root->left)
        dfs(root->left, sum, now, res, vi);
        if(root->right)
        dfs(root->right, sum, now, res, vi);
        vi.pop_back();
    }
};
