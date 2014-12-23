/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //Use BFS method and maintain a queue for it.
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> vvi;
        vector<int> vi;
        if(root == NULL) return vvi;
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
            else
            if(!vi.empty())
            {
                vvi.push_back(vi);
                vi.clear();
                 iq.push(x);
            }
        }
        return vvi;
    }
};
