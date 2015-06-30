/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // vector<int> vi should be built outside the loop,
 // in this case runtime is 12ms, or else 44ms.
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(!root) return res;
        bool flag = false;
        stack<TreeNode*> stree1, stree2;
        vector<int> vi;
        stree1.push(root);
        
        while(!stree1.empty() || !stree2.empty())
        {
            vi.clear();
            while(!stree1.empty())
            {
                TreeNode *p = stree1.top(); stree1.pop();
                vi.push_back(p->val);
                if(p->left) stree2.push(p->left);
                if(p->right) stree2.push(p->right);
            }
            res.push_back(vi);
            vi.clear();
            while(!stree2.empty())
            {
                TreeNode *p = stree2.top(); stree2.pop();
                vi.push_back(p->val);
                if(p->right) stree1.push(p->right);
                if(p->left) stree1.push(p->left);
            }
            if(!vi.empty())
                res.push_back(vi);
        }
        return res;
    }
};
