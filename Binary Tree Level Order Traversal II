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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> vvi;
        if(root == NULL) return vvi;
        vector<int> vi;
        TreeNode *x = new TreeNode('#');
        queue<TreeNode*> iq;
        iq.push(root);
        iq.push(x);
        while(!iq.empty())
        {
            TreeNode *i = iq.front();
            iq.pop();
            if(i != x)
            {
                vi.push_back(i->val);
                if(i->left) iq.push(i->left);
                if(i->right) iq.push(i->right);
                if(iq.empty()) break;
            }
            else if(!vi.empty())
            {
                vvi.push_back(vi);
                vi.clear();
                iq.push(x);
            }
        }
        if(vvi.size() > 1) reverse(vvi.begin(), vvi.end());
        return vvi;
    }
};
